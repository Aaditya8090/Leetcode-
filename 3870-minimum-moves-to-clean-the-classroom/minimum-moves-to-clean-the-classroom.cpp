class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<pair<int,int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    struct State{
        int row; 
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startR = 0;
        int startC = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                litterBit[r][c] = -1;
                if(classroom[r][c] == 'S'){
                    startR = r;
                    startC = c;
                }else if(classroom[r][c] == 'L'){
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        if(litterCount == 0)
            return 0;

        int allCollected = (1 << litterCount)-1;

        VVVVB visited(n, VVVB(m, VVB(maxEnergy+1, VB(1<<litterCount, false))));

        queue<State>q;
        q.push({startR, startC, maxEnergy, 0});
        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;
        while(!q.empty()){
            int currSize = q.size();

            while(currSize--){
                State curr = q.front();
                q.pop();

                if(curr.collectedMask == allCollected)
                    return moves;

                if(curr.energyLeft == 0)
                    continue;

                for(auto &[dr, dc]: dir){
                    int nextRow = curr.row + dr;
                    int nextCol = curr.col + dc;

                    if(nextRow <0 || nextRow>=n || nextCol<0 || nextCol >= m)
                        continue;
                    
                    char cell = classroom[nextRow][nextCol];
                    if(cell == 'X')continue;
                
                    int nextEnergy = curr.energyLeft - 1;
                    int nextCollectedMask = curr.collectedMask;

                    if(cell == 'R')
                        nextEnergy = maxEnergy;
                    else if(cell == 'L'){
                        nextCollectedMask |= (1<<litterBit[nextRow][nextCol]);
                    }

                    if(!visited[nextRow][nextCol][nextEnergy][nextCollectedMask]){
                        visited[nextRow][nextCol][nextEnergy][nextCollectedMask] = true;
                        q.push({nextRow, nextCol, nextEnergy, nextCollectedMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// T.C. =>  n * m * maxEnergy * 2^10
// S.C. =>  n * m * maxEnergy * 2^10