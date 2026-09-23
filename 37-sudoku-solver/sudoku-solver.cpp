class Solution {
public:
    bool isVal(int row, int col, char ch, vector<vector<char>>& board){
        // checking for row
        for(int r=0; r<9; r++){
            if(board[r][col] == ch)
                return false;
        }

        // checking for column
        for(int c=0; c<9; c++){
            if(board[row][c] == ch)
                return false;
        }

        // checking for subcell
        int start_row = 3 * (row/3);
        int start_col = 3 * (col/3);

        for(int r = start_row; r < start_row +3; r++){
            for(int c = start_col; c < start_col + 3; c++){
                if(board[r][c] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.')
                    continue;
                
                for(char ch = '1'; ch<= '9'; ch++){
                    if(isVal(i, j, ch, board)){
                        board[i][j] = ch;

                        if(solve(board))
                            return true;

                        board[i][j] = '.';
                    }
                }
                return false;  // No number worked
            }
        }
        return true;   // no empty cell means success (the only valid configuration)
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};