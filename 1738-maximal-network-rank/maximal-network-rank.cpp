class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>adj(n);
        for(auto &ro: roads){
            adj[ro[0]].insert(ro[1]);
            adj[ro[1]].insert(ro[0]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int rank = adj[i].size() + adj[j].size();

                bool isConnected = adj[i].find(j) != adj[i].end();
                if(isConnected)
                    rank--;

                ans = max(ans, rank);
            }
        }
        return ans;
    }
};