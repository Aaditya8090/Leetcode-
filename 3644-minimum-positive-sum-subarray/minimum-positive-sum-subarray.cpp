class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int mnp = INT_MAX;
        for(int i=0; i<n; i++){
            int curr=0;
            for(int j=i; j<min(n, i+r); j++){
                curr += nums[j];
                int len = j-i+1;
                if(len >= l && len<=r){
                    if(curr>0)
                        mnp = min(mnp, curr);
                }
            }
        }
        return mnp == INT_MAX ? -1 : mnp;
    }
};