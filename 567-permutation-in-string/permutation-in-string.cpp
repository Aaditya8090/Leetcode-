class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<int>need(26, 0), win(26,0);
        for(char &c: s1)
            need[c-'a']++;
        
        int req=m;
        for(int r=0; r<n; r++){
            int curr = s2[r]-'a';
            win[curr]++;
            if(win[curr] <= need[curr])
                req--;
            
            if(r >= m){
                int left = s2[r-m] - 'a';
                win[left]--;
                if(win[left] < need[left])
                    req++;
            }

            if(req == 0)
                return true;
        }
        return false;
    }
};