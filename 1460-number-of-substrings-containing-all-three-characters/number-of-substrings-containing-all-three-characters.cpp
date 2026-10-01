class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        int last[3] = {-1, -1, -1};
        for(int r=0; r<n; r++){
            last[s[r]-'a'] = r;

            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                int left = min(last[0], min(last[1], last[2]));
                
                // All starts 0 ... l are valid
                ans += left + 1;
            }
        }
        return ans;
    }
};