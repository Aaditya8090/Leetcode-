class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& ed : edges) {
            adj[ed[0]].push_back({ed[1], ed[2]});
        }

        using T = tuple<long long, int, int>; // dis, node, k
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));

        pq.push({0, 0, 1});
        dis[0][1] = 0;

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dis[u][cnt])
                continue;

            if (u == n - 1)
                return d;

            for (auto& [v, wt] : adj[u]) {
                int next_cnt;
                if (labels[u] == labels[v]) {
                    next_cnt = cnt + 1;
                } else {
                    next_cnt = 1;
                }

                if (next_cnt > k)
                    continue;

                if (d + wt < dis[v][next_cnt]) {
                    dis[v][next_cnt] = d + wt;
                    pq.push({dis[v][next_cnt], v, next_cnt});
                }
            }
        }
        return -1;
    }
};