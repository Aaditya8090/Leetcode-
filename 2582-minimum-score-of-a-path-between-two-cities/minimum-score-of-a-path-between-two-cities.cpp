class Solution {
public:
    using P = pair<int, int>;
    int ans = INT_MAX;

    void dfs(int src, vector<bool>&vis, vector<vector<P>>&adj){
        vis[src] = true;
        for(auto &[neigh, dis]: adj[src]){
            ans = min(ans, dis);
            if(!vis[neigh])
                dfs(neigh, vis, adj);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<P>>adj(n+1);
        for(auto &ro: roads){
            adj[ro[0]].push_back({ro[1], ro[2]});
            adj[ro[1]].push_back({ro[0], ro[2]});
        }

        vector<bool>vis(n+1, false);
        dfs(1, vis, adj);
        return ans;
    }
};