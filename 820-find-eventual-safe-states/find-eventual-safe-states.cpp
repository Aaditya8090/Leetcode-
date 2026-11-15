class Solution {
public:
    bool isCycleDfs(int src, vector<bool>&vis, vector<bool>&inRecursion, vector<vector<int>>& adj){
        vis[src] = true;
        inRecursion[src] = true;

        for(int neigh: adj[src]){
            if(!vis[neigh] && isCycleDfs(neigh, vis, inRecursion, adj))
                return true;
            else if(inRecursion[neigh]){
                return true;
            }
        }

        inRecursion[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>inRecursion(n, false), vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i])
                isCycleDfs(i, vis, inRecursion, graph);
        }

        vector<int>ans;
        for(int i=0; i<n; i++){
            if(!inRecursion[i])
                ans.push_back(i);
        }
        return ans;
    }
};