class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0)
                nums[i] = -1*nums[i];
        }
        sort(nums.begin(), nums.end());
        int m = (n+1)/2;
        long long sum1=0, sum2=0;
        for(int i=n-1; i>=n-m; i--){
            sum1 += (nums[i]*1LL*nums[i]);
        }
        for(int i=0; i<n-m; i++)
            sum2 += nums[i]*1LL*nums[i];

        return sum1-sum2;
    }
};