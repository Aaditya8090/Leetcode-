class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations using Pascal's Triangle
        comb.assign(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        
        // Subtract 1 to exclude the original array order
        return (dfs(nums) - 1 + MOD) % MOD;
    }

private:
    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        int L = left.size();
        int R = right.size();

        // ways = (leftWays * rightWays * C(L + R, L)) % MOD
        long long totalWays = (comb[L + R][L] * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }
};