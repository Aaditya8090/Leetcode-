class Solution {
public:
    int solve(int e, int f, vector<vector<int>>&dp){
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int mn = INT_MAX;
        int lo=1, hi=f;
        while(lo<=hi){
            int k = lo+(hi-lo)/2;
            int survive = dp[e][f-k] != -1? dp[e][f-k] : solve(e, f-k, dp);
            int breakk = dp[e-1][k-1] != -1 ? dp[e-1][k-1] : solve(e-1, k-1, dp);
            int worst_case = 1 + max(breakk, survive);
            mn = min(mn, worst_case);

            if(breakk < survive){
                lo = k+1;
            }else{
                hi = k-1;
            }

        }
        return dp[e][f] = mn;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};