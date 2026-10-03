class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int o_cnt = 0, c_cnt=0, len=0;

        for(int i=0; i<n; i++){
            if(s[i] == '(')
                o_cnt++;
            else
                c_cnt++;
            
            if(c_cnt == o_cnt){
                len = max(o_cnt+c_cnt, len);
            }else if(c_cnt > o_cnt){
                o_cnt = c_cnt = 0;
            }
        }

        o_cnt = c_cnt=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(')
                o_cnt++;
            else
                c_cnt++;
            
            if(c_cnt == o_cnt){
                len = max(o_cnt+c_cnt, len);
            }else if(o_cnt > c_cnt){
                o_cnt = c_cnt = 0;
            }
        }

        return len;
    }
};