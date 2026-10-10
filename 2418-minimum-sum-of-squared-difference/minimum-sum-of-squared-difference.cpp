class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> d(n);
        long long total_diff = 0;
        long long max_d = 0;
        
        for (int i = 0; i < n; ++i) {
            d[i] = abs((long long)nums1[i] - nums2[i]);
            total_diff += d[i];
            max_d = max(max_d, d[i]);
        }
        
        long long k = (long long)k1 + k2;
        if (total_diff <= k) return 0;
        
        // Binary search for the maximum difference `mid`
        long long low = 0, high = max_d, target = max_d;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;
            for (int i = 0; i < n; ++i) {
                if (d[i] > mid) {
                    ops += d[i] - mid;
                }
            }
            if (ops <= k) {
                target = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Apply reductions to target
        for (int i = 0; i < n; ++i) {
            if (d[i] > target) {
                k -= (d[i] - target);
                d[i] = target;
            }
        }
        
        // Distribute remaining operations
        for (int i = 0; i < n && k > 0; ++i) {
            if (d[i] == target && d[i] > 0) {
                d[i]--;
                k--;
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += d[i] * d[i];
        }
        return ans;
    }
};