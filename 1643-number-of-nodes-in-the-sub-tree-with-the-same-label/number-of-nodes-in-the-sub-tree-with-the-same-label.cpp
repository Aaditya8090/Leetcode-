class Solution {
public:
    vector<int>ans;
    void dfs(int src, int par, vector<int>&cnt, string &labels, vector<vector<int>>&adj){
        int before = cnt[labels[src]-'a'];
        cnt[labels[src]-'a']++;

        for(int neigh: adj[src]){
            if(neigh == par)continue;
            dfs(neigh, src, cnt, labels, adj);
        }
        int after = cnt[labels[src]-'a'];
        ans[src] = after-before;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vector<int>cnt(26, 0);
        ans.assign(n,0);
        dfs(0, -1, cnt, labels, adj);

        return ans;
    }
};