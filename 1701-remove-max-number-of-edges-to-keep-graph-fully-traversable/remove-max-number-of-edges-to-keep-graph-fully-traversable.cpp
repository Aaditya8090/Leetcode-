class Solution {
public:
    class DSU{
        public:
        vector<int>par,size;
        int components;
        DSU(int n){
            par.resize(n);
            size.resize(n, 1);
            iota(par.begin(), par.end(), 0);
            components=n;
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

            if(size[u]<size[v]){
                par[u] = v;
                size[v] += size[u];
            }else{
                par[v] = u;
                size[u] += size[v];
            }
            components--;
            return true;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        auto lambda = [](vector<int>&v1, vector<int>&v2){
            return v1[0]>v2[0];
        };
        sort(edges.begin(), edges.end(), lambda);

        DSU alice(n+1), bob(n+1);
        int ans=0;
        for(auto &ed: edges){
            int type = ed[0];
            int u = ed[1];
            int v = ed[2];

            if(type == 3){
                bool mergedA = alice.merge(u, v);
                bool mergedB = bob.merge(u, v);
                if(!mergedA || !mergedB)ans++;  // mergedA and mergedB will always be equal
            }else if(type == 2){
                if(!bob.merge(u, v))
                    ans++;
            }else{
                if(!alice.merge(u, v))
                    ans++;
            }
        }

        if(alice.components >2 || bob.components>2)
            return -1;
        return ans;
    }
};