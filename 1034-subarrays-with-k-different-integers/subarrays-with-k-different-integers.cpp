class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int n = nums.size();
        unordered_map<int, int>mp;
        int uniq=0, l=0, cnt=0;

        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            if(mp[nums[r]] == 1)
                uniq++;
            
            while(uniq > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    uniq--;
                l++;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};