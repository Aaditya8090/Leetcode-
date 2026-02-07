class Solution {
public:
    int minimumDeletions(string s) {
        int ta=0, tb=0, la=0, lb=0;
        for(char c: s)
            if(c=='a')
                ta++;
            else
                tb++;
        int ans = ta;
        for(char c: s){
            if(c=='a')
                la++;
            else
                lb++;
            ans = min(ans, ta-la+lb);
        }
        return ans;
    }
};