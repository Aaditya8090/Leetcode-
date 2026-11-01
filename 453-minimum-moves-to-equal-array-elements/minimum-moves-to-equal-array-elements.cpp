class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);

        return sum - mn*1ll*nums.size();
    }
};