#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, orig_idx;
    };

    struct State {
        long long weight = -1;
        vector<int> indices;
        bool valid = false;
    };

    // Helper to compare two DP states: higher weight is preferred, 
    // and lexicographically smaller index list breaks ties.
    bool isBetter(long long w1, const vector<int>& idx1, long long w2, const vector<int>& idx2) {
        if (w1 != w2) return w1 > w2;
        return idx1 < idx2;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by left boundary ascending
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.orig_idx < b.orig_idx;
        });

        // dp[i][c]: best state picking EXACTLY c non-overlapping intervals from suffix starting at index i
        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Base case: 0 intervals picked has weight 0 and empty index list
        for (int i = 0; i <= n; ++i) {
            dp[i][0].weight = 0;
            dp[i][0].indices = {};
            dp[i][0].valid = true;
        }

        for (int i = n - 1; i >= 0; --i) {
            // Find first interval j such that sorted_intervals[j].l > sorted_intervals[i].r
            auto it = upper_bound(sorted_intervals.begin(), sorted_intervals.end(), sorted_intervals[i].r,
                [](int val, const Interval& inv) {
                    return val < inv.l;
                }
            );
            int nxt = distance(sorted_intervals.begin(), it);

            for (int c = 1; c <= 4; ++c) {
                // Option 1: Do not pick sorted_intervals[i]
                State best_state = dp[i + 1][c];

                // Option 2: Pick sorted_intervals[i]
                if (dp[nxt][c - 1].valid) {
                    long long new_weight = (long long)sorted_intervals[i].weight + dp[nxt][c - 1].weight;
                    vector<int> new_indices = dp[nxt][c - 1].indices;
                    auto pos = lower_bound(new_indices.begin(), new_indices.end(), sorted_intervals[i].orig_idx);
                    new_indices.insert(pos, sorted_intervals[i].orig_idx);

                    if (!best_state.valid || isBetter(new_weight, new_indices, best_state.weight, best_state.indices)) {
                        best_state = {new_weight, new_indices, true};
                    }
                }

                dp[i][c] = best_state;
            }
        }

        // Find the best choice among picking 1, 2, 3, or 4 intervals
        State ans;
        for (int c = 1; c <= 4; ++c) {
            if (dp[0][c].valid) {
                if (!ans.valid || isBetter(dp[0][c].weight, dp[0][c].indices, ans.weight, ans.indices)) {
                    ans = dp[0][c];
                }
            }
        }

        return ans.indices;
    }
};