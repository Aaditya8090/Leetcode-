class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int required = t.size();

        vector<int>win(128, 0), need(128, 0);
        for(char c: t)
            need[c]++;
        
        int l=0, bestLen=INT_MAX, bestStart=0;
        for(int r=0; r<n; r++){
            win[s[r]]++;

            if(win[s[r]] <= need[s[r]])
                required--;

            while(required == 0){
                if(r-l+1 < bestLen){
                    bestLen = r-l+1;
                    bestStart = l;
                }

                char leftChar = s[l];
                win[leftChar]--;
                if(win[leftChar] < need[leftChar])
                    required++;

                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};