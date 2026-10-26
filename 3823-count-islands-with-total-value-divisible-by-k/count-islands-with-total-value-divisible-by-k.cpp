class Solution {
public:
    int n,m;
    vector<pair<int, int>>dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isVal(int r, int c){
        if(r<0 || r>=n || c<0 || c>= m)
            return false;
        return true;
    }

    int dfs(int r, int c, int k, vector<vector<int>>& grid){
        int sum = grid[r][c];

        grid[r][c] = 0;

        for(auto &[dr, dc]: dir){
            int nr = r + dr;
            int nc = c + dc;

            if(isVal(nr, nc) && grid[nr][nc]>0){
                sum = (sum + dfs(nr, nc, k, grid))%k;
            }
        }
        return sum%k;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    count += dfs(i, j, k, grid) == 0 ? 1 : 0;
                }
            }
        }
        return count;
    }
};