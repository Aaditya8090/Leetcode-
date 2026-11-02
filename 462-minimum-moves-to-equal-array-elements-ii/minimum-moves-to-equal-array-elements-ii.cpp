class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), cnt=0;

        sort(nums.begin(), nums.end());

        int mid = nums[n/2];
        for(int i: nums){
            cnt += abs(i-mid);
        }
        return cnt;
    }
};