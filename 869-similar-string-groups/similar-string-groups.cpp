class Solution {
public:
    bool isSimilar(string &s1, string &s2){
        int i=0, j=0, cnt=0, n=s1.size();

        for(int i=0; i<n; i++){
            cnt += s1[i]!=s2[i];
            if(cnt>2)return false;
        }

        return true;
    }

    void dfs(int src, vector<bool>&vis, vector<vector<int>>&adj){
        vis[src] = true;
        for(int neigh: adj[src]){
            if(!vis[neigh])
                dfs(neigh, vis, adj);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt=0;
        vector<bool>vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};