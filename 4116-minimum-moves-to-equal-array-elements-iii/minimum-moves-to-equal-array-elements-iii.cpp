class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
            ans += (mx-nums[i]);
        return ans;
    }
};