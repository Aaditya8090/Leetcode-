class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int cnt = 0, curr=0, l=0, n=nums.size();
        for(int r=0; r<n; r++){
            if(nums[r]%2 == 1)
                curr++;
            
            while(curr>k){
                if(nums[l]%2 == 1)
                    curr--;
                l++;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};