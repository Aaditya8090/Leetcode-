class Solution {
public:
    int dp[101][101][101];
    bool solve(int i, int o_cnt, int c_cnt, string &s){
        if(i == s.size()){
            return o_cnt == c_cnt;
        }
        if(dp[i][o_cnt][c_cnt]!= -1)
            return dp[i][o_cnt][c_cnt];

        if(o_cnt>s.size()/2)
            return dp[i][o_cnt][c_cnt] = false;

        if(s[i] == '('){
            if(solve(i+1, o_cnt+1, c_cnt, s))
                return dp[i][o_cnt][c_cnt] = true;
        }else if(s[i] == ')' && o_cnt>c_cnt){
            if(solve(i+1, o_cnt, c_cnt+1, s))
                return dp[i][o_cnt][c_cnt] = true;
        }else if(s[i] == '*'){
            if(solve(i+1, o_cnt+1, c_cnt, s))
                return dp[i][o_cnt][c_cnt] = true;
            else if(o_cnt>c_cnt && solve(i+1, o_cnt, c_cnt+1, s))
                return dp[i][o_cnt][c_cnt] = true;
            else if(solve(i+1, o_cnt, c_cnt, s))
                return dp[i][o_cnt][c_cnt] = true;
        }
        return dp[i][o_cnt][c_cnt] = false;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s);
    }
};