class Solution {
public:
    vector<int>parent, rank;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u==v)return;

        if(rank[u]>rank[v]){
            parent[v] = u;
        }else if(rank[v]>rank[u]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>>adj(n);
        for(auto ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);

        map<int, vector<int>>val_to_nodes;
        for(int i=0; i<n; i++){
            val_to_nodes[vals[i]].push_back(i);
        }

        int ans=0;
        vector<bool>active(n, false);

        for(auto &[val, nodes]: val_to_nodes){
            for(int &u: nodes){
                for(int &v: adj[u]){
                    if(active[v]){
                        merge(u, v);
                    }
                }
                active[u] = true;
            }

            unordered_map<int, int>mp;  // number of nodes in diff connected compopnent 
            for(int &u: nodes){
                mp[find(u)]++;
            }

            for(auto &[par, cnt]: mp){
                ans += cnt*(cnt-1)/2 + cnt;  // kC2 + k
            }
        }

        return ans;
    }
};

// merge nodes using DSU in the increasing order of their values which ensures that if we are finding number of good paths for a current val then higher value should not be present at that time
// for finding number of good path in a connected component we need two nodes in that component for making a good path so nC2 + n(bcz nodes itself are good path)
// nC2 = n*(n-1)/2;