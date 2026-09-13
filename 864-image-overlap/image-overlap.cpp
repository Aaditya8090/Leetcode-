class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans=0;
        map<pair<int, int>, int>mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]!= 1)
                    continue;
                for(int a=0; a<n; a++){
                    for(int b=0; b<n; b++){
                        if(img2[a][b] == 1){
                            mp[{i-a, j-b}]++;
                        }
                    }
                }
            }
        }
        for(auto &[a, b]: mp){
            ans = max(ans, b);
        }
        return ans;
    }
};