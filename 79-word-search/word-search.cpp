class Solution {
public:
    vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1,0}};

    bool isVal(int r, int c, int n, int m){
        if(r<0 || c<0 || r>=n || c>= m)
            return false;
        return true;
    }

    bool solve(int r, int c, int idx, vector<vector<char>>& board, string &word){
        int n = board.size();
        int m = board[0].size();

        if(idx == word.size())
            return true;
        
        if (!isVal(r, c, board.size(), board[0].size()) || board[r][c] != word[idx]) 
            return false;
        
        char tmp = board[r][c];
        board[r][c] = '#';

        for(auto &[dr, dc]: d){
            int nr = r + dr;
            int nc = c + dc;

            if(solve(nr, nc, idx+1, board, word))
                return true;
        }

        board[r][c] = tmp; // Backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && solve(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};