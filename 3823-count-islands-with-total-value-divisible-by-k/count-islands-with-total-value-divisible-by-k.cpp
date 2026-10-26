class Solution {
public:
    int n,m;
    vector<pair<int, int>>dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isVal(int r, int c){
        if(r<0 || r>=n || c<0 || c>= m)
            return false;
        return true;
    }

    long long dfs(int r, int c, vector<vector<int>>& grid){
        long long sum = grid[r][c];

        grid[r][c] = 0;

        for(auto &[dr, dc]: dir){
            int nr = r + dr;
            int nc = c + dc;

            if(isVal(nr, nc) && grid[nr][nc]>0){
                sum += dfs(nr, nc, grid);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    count += dfs(i, j, grid) % k == 0 ? 1 : 0;
                }
            }
        }
        return count;
    }
};