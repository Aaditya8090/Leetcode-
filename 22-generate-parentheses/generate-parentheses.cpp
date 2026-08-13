class Solution {
public:
    vector<string>ans;
    void gen(int open_cnt, int close_cnt, string s, int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open_cnt < n && open_cnt >= close_cnt){
            s.push_back('(');
            gen(open_cnt+1, close_cnt, s, n);
            s.pop_back();
        }

        if(close_cnt < open_cnt){
            s.push_back(')');
            gen(open_cnt, close_cnt+1, s, n);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        gen(0, 0, "", n);
        return ans;
    }
};