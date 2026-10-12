class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        
        vector<long long> top_k(k, 0);
        for (int i = 31; i >= 0; --i) {
            int count = bit_count[i];
            for (int j = 0; j < k && j < count; ++j) {
                top_k[j] |= (1LL << i);
            }
        }
        
        long long mod = 1e9 + 7;
        long long ans = 0;
        for (long long x : top_k) {
            ans = (ans + (x * x) % mod) % mod;
        }
        
        return ans;
    }
};