class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans=0;
        for(char c: s){
            cnt += c == '(' ? 1 : -1;
            if(cnt<0 && c == ')'){
                ans++;
                cnt=0;
            }
        }
        return ans + cnt;
    }
};