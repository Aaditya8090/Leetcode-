#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int prod;
    int cnt[5];
    Node() {
        prod = 1;
        memset(cnt, 0, sizeof(cnt));
    }
};

class Solution {
    vector<Node> tree;
    int K;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        for (int r = 0; r < K; r++) {
            res.cnt[r] = left.cnt[r];
        }
        for (int r = 0; r < K; r++) {
            int new_rem = (left.prod * r) % K;
            res.cnt[new_rem] += right.cnt[r];
        }
        return res;
    }

    void build(const vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, 2 * node, l, mid);
        build(nums, 2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            int rem = val % K;
            memset(tree[node].cnt, 0, sizeof(tree[node].cnt));
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }
        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }
        return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        int n = nums.size();
        tree.assign(4 * n, Node());
        
        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            // Point update persists across queries
            update(1, 0, n - 1, idx, val);
            
            // Query range [start, n - 1]
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};