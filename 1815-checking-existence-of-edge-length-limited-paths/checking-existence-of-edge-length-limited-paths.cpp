class Solution {
public:
    vector<int>par, size;
    int find(int i){
        if(par[i] == i)
            return i;
        return find(par[i]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v)return;
        if(size[u]<size[v]){
            par[u] = v;
            size[v] += size[u];
        }else{
            par[v] = u;
            size[u] += size[v];
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        par.resize(n);
        size.resize(n, 1);
        iota(par.begin(), par.end(), 0);

        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }

        auto lambda = [](vector<int>v1, vector<int>&v2){
            return v1[2]<v2[2];
        };

        sort(edgeList.begin(), edgeList.end(), lambda);
        sort(queries.begin(), queries.end(), lambda);

        int j=0; vector<bool>ans(queries.size(), false);
        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int dis = queries[i][2];
            int idx = queries[i][3];

            while(j<edgeList.size() && edgeList[j][2] < dis){
                merge(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            ans[idx] = find(u) == find(v);
        }
        return ans;
    }
};