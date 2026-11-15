class Solution {
public:
    int bfs(int src, vector<vector<int>>&adj){
        int n = adj.size();
        int cnt = 0;

        queue<int>q;
        vector<bool>vis(n, false);
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop(); cnt++;

            for(int neigh: adj[curr]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            long long r = bombs[i][2];
            
            for(int j=0; j<n; j++){
                if(i == j)continue;

                long long dx = bombs[i][0]-bombs[j][0];
                long long dy = bombs[i][1]-bombs[j][1];

                if(dx*dx + dy*dy <= r*r){
                    adj[i].push_back(j);
                }
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, bfs(i, adj));
        }
        return ans;
    }
};