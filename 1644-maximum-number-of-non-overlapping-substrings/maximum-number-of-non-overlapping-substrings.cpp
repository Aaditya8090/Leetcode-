#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> left(26, -1), right(26, -1);
        
        // Step 1: Find first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (left[ch] == -1) left[ch] = i;
            right[ch] = i;
        }

        vector<pair<int, int>> intervals; // stores {right_bound, left_bound}

        // Step 2: Expand valid substrings starting at each character's first occurrence
        for (int i = 0; i < 26; ++i) {
            if (left[i] == -1) continue;

            int l = left[i];
            int r = right[i];
            bool valid = true;

            for (int j = l; j <= r; ++j) {
                int ch = s[j] - 'a';
                // If a character inside requires extending left of left[i], this start is invalid
                if (left[ch] < left[i]) {
                    valid = false;
                    break;
                }
                r = max(r, right[ch]);
            }

            if (valid) {
                intervals.push_back({r, l});
            }
        }

        // Step 3: Sort candidate intervals by their end index ascending
        sort(intervals.begin(), intervals.end());

        // Step 4: Greedily pick non-overlapping intervals
        vector<string> result;
        int last_end = -1;

        for (const auto& [r, l] : intervals) {
            if (l > last_end) {
                result.push_back(s.substr(l, r - l + 1));
                last_end = r;
            }
        }

        return result;
    }
};