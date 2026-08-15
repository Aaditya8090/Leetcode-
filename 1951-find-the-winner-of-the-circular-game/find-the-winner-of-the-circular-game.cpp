class Solution {
public:
    int ans;
    void solve(vector<int>&v, int idx, int k){
        if(v.size()==1){
            ans = v[0];
            return;
        }

        idx = (idx + k)%v.size();
        v.erase(v.begin()+idx);

        solve(v, idx, k);
    }

    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0; i<n; i++)
            v[i] = i+1;
        k--;

        solve(v, 0, k);

        return ans;
    }
};