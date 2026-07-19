class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        string res;
        vector<bool>vis(26, false);

        unordered_map<char, int>mp;
        for(int i=0; i<n; i++)
            mp[s[i]] = i;

        for(int i=0; i<n; i++){
            char ch = s[i];
            int idx = ch-'a';

            if(vis[idx] == true)
                continue;
            
            while(res.length()>0 && res.back() > ch && mp[res.back()]>i){
                vis[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            vis[idx] = true;
        }
        return res;
    }
};