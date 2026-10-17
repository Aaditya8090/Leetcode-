#include <vector>
#include <algorithm>

class Solution {
public:
    // Helper function to calculate the sum of digits
    int sum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // Pair each element with its original index: {value, original_index}
        std::vector<std::pair<int, int>> cur(n);
        for (int i = 0; i < n; i++) {
            cur[i] = {nums[i], i};
        }

        // Sort based on your custom rules:
        // 1. Digit sum (ascending)
        // 2. Numerical value if sums are equal (ascending)
        std::sort(cur.begin(), cur.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            int sum1 = sum(a.first);
            int sum2 = sum(b.first);
            if (sum1 != sum2) return sum1 < sum2;
            return a.first < b.first;
        });

        std::vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // If already visited or already in the correct sorted spot, skip
            if (visited[i] || cur[i].second == i) {
                continue;
            }

            // Calculate the size of the cycle
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = cur[j].second; // Move to the next index in the cycle
                cycle_size++;
            }

            // A cycle of size K requires (K - 1) swaps to fix
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }

        return ans;
    }
};
