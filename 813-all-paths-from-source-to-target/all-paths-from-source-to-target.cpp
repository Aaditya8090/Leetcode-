class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int src, vector<int>&path, vector<vector<int>>& graph, int n){
        path.push_back(src);

        if(src == n-1){
            ans.push_back(path);
        }

        for(int neigh: graph[src]){
            dfs(neigh, path, graph, n);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>path;
        dfs(0, path, graph, n);
        return ans;
    }
};