class Solution {
public:
    int dfs(int src, vector<bool>&vis, vector<bool>& hasApple, vector<vector<int>>&adj){
        vis[src] = true;

        int children = 0;
        for(int neigh: adj[src]){
            if(!vis[neigh])
                children += dfs(neigh, vis, hasApple, adj);
        }

        if(hasApple[src] || children>0){
            return 2 + children;
        }
        return 0;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vector<bool>vis(n, false);
        int ans = dfs(0, vis, hasApple, adj);
        return ans>0 ? ans-2 : 0;
    }
};