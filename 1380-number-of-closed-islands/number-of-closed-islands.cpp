class Solution {
public:
    vector<pair<int, int>>dir = {{0,-1}, {0, 1}, {-1, 0}, {1,0}};

    bool isVal(int r, int c, int n, int m){
        if(r<0 || r>=n || c<0 || c>=m)
            return false;
        return true;
    }

    bool inVal(int r, int c, int n, int m){
        if(r == 0 || r == n-1 || c == 0 || c == m-1)
            return true;
        return false;
    }

    void dfs(int i, int j, bool &flag, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        grid[i][j] = 1;

        if(inVal(i, j, n, m))
            flag = false;
        
        for(auto &[dr, dc]: dir){
            int nr = i+dr;
            int nc = j+dc;

            if(isVal(nr, nc, n, m) && grid[nr][nc] == 0)
                dfs(nr, nc, flag, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    bool flag = true;
                    dfs(i, j, flag, grid);
                    if(flag)cnt++;
                }
            }
        }
        return cnt;
    }
};