class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxIdx = 0, n=nums.size();
        for(int i=0; i<n; i++){
            if(mxIdx >= n-1)
                return true;

            if(mxIdx >= i){
                mxIdx = max(mxIdx, nums[i]+i);
            }else{
                return false;
            }
        }
        return true;
    }
};