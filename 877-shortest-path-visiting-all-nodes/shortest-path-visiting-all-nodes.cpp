class Solution {
public:
    int dfs(int src, int &count, vector<bool>&vis, vector<vector<int>>& graph){
        vis[src] = true; count++;
        int cnt=0;
        for(int neigh: graph[src]){
            if(!vis[neigh]){
                cnt += 1+ dfs(neigh, count, vis, graph);
            }
        }
        if(count<graph.size())cnt++;
        return cnt;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1<<n) -1;

        queue<pair<int, int>>q;  // node, mask
        vector<vector<bool>>vis(n, vector<bool>(1<<n, false));
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            vis[i][mask] = true;
            q.push({i, mask});
        }

        int steps=0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [node, mask] = q.front();
                q.pop();

                if(mask == allVisited)
                    return steps;

                for(int neigh: graph[node]){
                    int nextMask = mask | (1<<neigh);
                    if(!vis[neigh][nextMask]){
                        vis[neigh][nextMask] = true;
                        q.push({neigh, nextMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};

//Time Complexity: O(n*2^n) because there are n possible nodes and 2^n possible bitmasks.