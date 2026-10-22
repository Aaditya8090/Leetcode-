class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int cnt = 0, curr_jump_end = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            int farthest = max(farthest, i + nums[i]);

            if (i == curr_jump_end) {
                cnt++;
                curr_jump_end = farthest;
            }
        }
        return cnt;
    }
};