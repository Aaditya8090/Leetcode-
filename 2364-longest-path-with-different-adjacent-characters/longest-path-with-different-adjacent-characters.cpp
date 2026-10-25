class Solution {
public:
    int ans = 0;
    int dfs(int src, vector<vector<int>>&adj, string &s){
        int largest=0, secLargest=0;
        for(int neigh: adj[src]){
            int curr = dfs(neigh, adj, s);

            if(s[neigh] == s[src])
                continue;

            if(curr > secLargest)
                secLargest = curr;
            if(secLargest > largest)
                swap(largest, secLargest);
        }
        ans = max(ans, 1+largest+secLargest);
        return 1 + max(largest, secLargest);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>>adj(n);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }

        dfs(0, adj, s);
        return ans;
    }
};