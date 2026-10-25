class Solution {
public:
    int n, m;
    vector<pair<int, int>>dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isVal(int r, int c, int n, int m){
        if(r<0 || r>=n || c<0 || c>= m){
            return false;
        }
        return true;
    }

    bool isPoss(int mid, vector<vector<int>>& t, vector<vector<int>>& grid){
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<pair<int, int>>q;

        q.push({0, 0});
        vis[0][0] = true;

        while(!q.empty()){
            int size = q.size();
            mid++;

            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(auto &[dr, dc]: dir){
                    int nr = r + dr;
                    int nc = c + dc;

                    if(isVal(nr, nc, n, m) && grid[nr][nc] == 0 && !vis[nr][nc]){
                        if(nr == n-1 && nc == m-1 && mid<=t[nr][nc])
                            return true;
                        else if(mid < t[nr][nc]){
                            q.push({nr, nc});
                            vis[nr][nc] = true;
                        }
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // time for fire to reach {i, j}
        vector<vector<int>>t(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    t[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(auto &[dr, dc]: dir){
                    int nr = dr + r;
                    int nc = dc + c;

                    if(isVal(nr, nc, n, m) && grid[nr][nc] == 0 && t[nr][nc] == INT_MAX){
                        t[nr][nc] = t[r][c]+1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        int l=0, r=1e9, ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPoss(mid, t, grid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};