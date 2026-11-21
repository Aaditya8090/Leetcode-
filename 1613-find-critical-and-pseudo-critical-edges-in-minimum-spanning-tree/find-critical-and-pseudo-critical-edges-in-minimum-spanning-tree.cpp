class Dsu{
    public:
    vector<int>par, size;
    Dsu(int n){
        size.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x){
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    bool merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v)return false;

        if(size[u] > size[v]){
            par[v] = u;
            size[u] += size[v];
        }else{
            par[u] = v;
            size[v] += size[u];
        }
        return true;
    }
};

class Solution {
public:
    int V;
    int kruskal(vector<vector<int>>& edge, int skip, int take){
        int n = edge.size();
        Dsu dsu(V);

        int wt = 0;

        if(take != -1){
            dsu.merge(edge[take][0], edge[take][1]);
            wt += edge[take][2];
        }

        for(int i=0; i<n; i++){
            if(i == skip)continue;

            int u = edge[i][0];
            int v = edge[i][1];

            if(dsu.merge(u, v)){
                wt += edge[i][2];
            }
        }

        for(int i=0; i<V; i++){
            if(dsu.find(i) != dsu.find(0))
                return INT_MAX;
        }
        return wt;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        V = n;
        int N = edges.size();
        for(int i=0; i<N; i++){
            edges[i].push_back(i);
        }

        auto lambda = [](vector<int>&a, vector<int>&b){
            return a[2]<b[2];
        };

        sort(edges.begin(), edges.end(), lambda);

        int MST_WT = kruskal(edges, -1, -1);

        vector<int>critical, pseudo;
        for(int i=0; i<N; i++){
            if(kruskal(edges, i, -1) > MST_WT){
                critical.push_back(edges[i][3]);
            }else if(kruskal(edges, -1, i) == MST_WT){
                pseudo.push_back(edges[i][3]);
            }
        }

        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(pseudo);

        return ans;
    }
};