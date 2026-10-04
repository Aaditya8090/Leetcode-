class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        stack<int>minSt;
        long long minSum = 0;
        for(int i=0; i<=n; i++){
            int curr = (i==n) ? INT_MIN : nums[i];

            while(!minSt.empty() && curr < nums[minSt.top()]){
                int mid = minSt.top();
                minSt.pop();

                int left_bound = minSt.empty() ? -1 : minSt.top();
                int right_bound = i;

                minSum += (mid-left_bound)*(right_bound-mid)*1ll*nums[mid];
            }
            minSt.push(i);
        }


        stack<int>maxSt;
        long long maxSum = 0;
        for(int i=0; i<=n; i++){
            int curr = (i==n) ? INT_MAX : nums[i];

            while(!maxSt.empty() && curr > nums[maxSt.top()]){
                int mid = maxSt.top();
                maxSt.pop();

                int left_bound = maxSt.empty() ? -1 : maxSt.top();
                int right_bound = i;

                maxSum += (mid-left_bound)*(right_bound-mid)*1ll*nums[mid];
            }
            maxSt.push(i);
        }
        return maxSum-minSum;
    }
};