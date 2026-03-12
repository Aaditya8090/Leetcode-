class Solution {
public:
    int linRob(vector<int>&nums, int start, int end){
        int prev1=0, prev2=0;
        for(int i=start; i<=end; i++){
            int tmp = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];

        // first approach    O(n) space complexity

        // int ans= 0;
        // vector<int>dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for(int i=2; i<n-1; i++)
        //     dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        // ans = dp[n-2];

        // dp.assign(n,0);
        // dp[1] = nums[1];
        // if(n>2)
        //     dp[2] = max(nums[1], nums[2]);
        // for(int i=3; i<n; i++)
        //     dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        // return max(ans, dp[n-1]);


        // 2nd approach  O(1) Space complexity
        
        int first = linRob(nums, 0, n-2);
        int sec = linRob(nums, 1, n-1);
        return max(first, sec);
    }
};