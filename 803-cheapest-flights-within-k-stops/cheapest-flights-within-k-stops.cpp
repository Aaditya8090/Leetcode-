class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto &ed: flights){
            adj[ed[0]].push_back({ed[1], ed[2]});
        }
        
        int stop=0; 
        vector<int>dist(n, INT_MAX);
        queue<pair<int, int>>q;

        dist[src]=0;
        q.push({src, 0});

        while(!q.empty() && stop<=k){
            int size = q.size();
            while(size--){
                auto [curr, curr_dist] = q.front();
                q.pop();

                for(auto &[neigh, dis]: adj[curr]){
                    if(curr_dist + dis < dist[neigh]){
                        dist[neigh] = curr_dist+dis;
                        q.push({neigh, dist[neigh]});
                    }
                }
            }
            stop++;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};