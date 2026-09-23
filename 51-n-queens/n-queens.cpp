class Solution {
public:
    vector<vector<string>>ans;

    bool isVal(int row, int col, vector<string>&b){
        int n = b.size();

        // check for same column before curr row
        for(int r=0; r<row; r++){
            if(b[r][col] == 'Q')
                return false;
        }

        // check for left-digonal before curr row
        for(int r=row-1, c=col-1; r>=0 && c>=0; r--,c--){
            if(b[r][c] == 'Q')
                return false;
        }

        // check for right diagonal before curr row
        for(int r=row-1, c=col+1; r>=0 && c<n; r--, c++){
            if(b[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int r, vector<string>&b){
        if(r == b.size()){
            ans.push_back(b);
            return;
        }

        for(int c=0; c<b.size(); c++){
            if(isVal(r, c, b)){
                b[r][c] = 'Q';
                solve(r+1, b);
                b[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>tmp(n, string(n, '.'));
        solve(0, tmp);
        return ans;
    }
};