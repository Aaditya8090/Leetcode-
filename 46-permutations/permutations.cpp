class Solution {
public:
    void backtrack(vector<int>&curr, vector<int>&nums, vector<bool>&used, vector<vector<int>>&ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int num: nums){
            if(used[num+10])
                continue;

            used[num+10] = true;
            curr.push_back(num);

            backtrack(curr, nums, used, ans);

            used[num+10] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<bool>used(21, false);
        vector<int>curr;

        backtrack(curr, nums, used, ans);
        return ans;
    }
};