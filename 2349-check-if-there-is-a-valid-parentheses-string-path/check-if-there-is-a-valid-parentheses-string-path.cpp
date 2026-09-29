class Solution {
public:
    int dp[101][101][201];  // max len of the parentheses will be n+m-1

    bool solve(int r, int c, int o_cnt, vector<vector<char>>& grid){
        int n = grid.size(); int m = grid[0].size();

        o_cnt += (grid[r][c] == '(') ? 1 : -1;

        if(o_cnt<0)return false;

        if(dp[r][c][o_cnt] != -1)
            return dp[r][c][o_cnt];

        if(r == n-1 && c == m-1)
            return dp[r][c][o_cnt] = (o_cnt == 0);
        
        // right
        if(c+1 < m){
            if(solve(r, c+1, o_cnt, grid))
                return dp[r][c][o_cnt] = true;
        }

        // down
        if(r+1 < n){
            if(solve(r+1, c, o_cnt, grid))
                return dp[r][c][o_cnt] = true;
        }

        return dp[r][c][o_cnt] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();

        if(grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;
        
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};