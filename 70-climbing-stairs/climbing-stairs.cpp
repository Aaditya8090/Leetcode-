class Solution {
public:
    int climbStairs(int n) {
        // 1-D dp
        
        // first approach  -> O(n) time  and O(n) space
        // vector<int>dp(n+1,0);
        // dp[0] = dp[1] = 1; 
        // for(int i=2; i<=n; i++)
        //     dp[i] = dp[i-1]+dp[i-2];
        // return dp[n];


        // second approach  -> O(n) time and O(1) space
        int prev1=1, prev2=1;
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};