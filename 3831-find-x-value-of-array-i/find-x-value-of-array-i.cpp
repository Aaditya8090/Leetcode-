#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            std::vector<long long> next_dp(k, 0);

            // 1. Subarray consisting of just nums[i]
            next_dp[val]++;

            // 2. Extend existing subarrays ending at previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (r * val) % k;
                    next_dp[next_rem] += dp[r];
                }
            }

            dp = std::move(next_dp);

            // Accumulate counts for subarrays ending at current index
            for (int r = 0; r < k; ++r) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};