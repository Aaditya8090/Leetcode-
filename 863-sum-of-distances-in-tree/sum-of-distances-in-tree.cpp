class Solution {
public:
    int fstVal = 0;
    vector<int>nodeInSub, ans;
    void dfs1(int src, int par, int depth, vector<vector<int>>&adj, int n){
        fstVal += depth;

        nodeInSub[src]++;
        for(int neigh: adj[src]){
            if(neigh == par)continue;
            dfs1(neigh, src, depth+1, adj, n);
            nodeInSub[src] += nodeInSub[neigh];
        }
    }

    void dfs2(int src, int par, int par_val, vector<vector<int>>&adj, int n){
        ans[src] = par_val + n - 2*nodeInSub[src];

        for(int neigh: adj[src]){
            if(neigh == par)
                continue;
            dfs2(neigh, src, ans[src], adj, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nodeInSub.assign(n, 0);
        ans.assign(n, 0);

        vector<vector<int>>adj(n);
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        dfs1(0, -1, 0, adj, n);
        ans[0] = fstVal;

        for(int child: adj[0])
            dfs2(child, 0, fstVal, adj, n);

        return ans;
    }
};