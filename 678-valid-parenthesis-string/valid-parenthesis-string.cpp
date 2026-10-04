class Solution {
public:
    int dp[101][101];
    bool solve(int i, int open, string &s){
        if(i == s.size()){
            return open == 0;
        }

        if(dp[i][open] != -1)
            return dp[i][open];

        bool isValid = false;
        if(s[i] == '*'){
            isValid |= solve(i+1, open+1, s);
            isValid |= solve(i+1, open, s);
            if(open>0)
                isValid |= solve(i+1, open-1, s);
        }else if(s[i] == '('){
            isValid |= solve(i+1, open+1, s);
        }else if(open>0){
            isValid |= solve(i+1, open-1, s);
        }
        return dp[i][open] = isValid;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);


        // Bottom up
        int n = s.size();
        vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));
        // dp[i][j]  => i to n-1 having seen j open brackets 
        dp[n][0] = true;
        // dp[n][1] = dp[n][2] = ....... = dp[n][n] = false;

        for(int i=n-1; i>=0; i--){
            bool isValid = false;
            for(int open=0; open <=n; open++){
                if(s[i] == '*'){
                    isValid |= dp[i+1][open+1];
                    isValid |= dp[i+1][open];
                    if(open>0)
                        isValid |= dp[i+1][open-1];
                }else if(s[i] == '('){
                    isValid |= dp[i+1][open+1];
                }else if(open>0){
                    isValid |= dp[i+1][open-1];
                }

                dp[i][open] = isValid;
            }
        }
        return dp[0][0];
    }
};