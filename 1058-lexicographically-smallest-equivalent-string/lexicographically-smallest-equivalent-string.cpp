class Solution {
public:
    void dfs(char src, char par, char &mn, vector<bool>&vis, unordered_map<char, vector<char>>&mp){
        vis[src-'a'] = true;
        for(char neigh: mp[src]){
            if(neigh == par)continue;
            if(vis[neigh-'a'])continue;
            mn = min(neigh, mn);
            dfs(neigh, src, mn, vis, mp);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        unordered_map<char, vector<char>>mp;
        for(int i=0; i<n; i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }

        string ans = "";
        for(char c: baseStr){
            char tmp = c;
            vector<bool>vis(26, false);
            dfs(c, '*', tmp, vis, mp);
            ans.push_back(tmp);
        }
        return ans;
    }
};