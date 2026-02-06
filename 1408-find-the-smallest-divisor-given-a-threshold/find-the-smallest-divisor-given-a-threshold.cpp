class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l<r){
            int mid = l + (r-l)/2;
            long long sum=0;
            for(int i=0; i<n; i++){
                sum += (nums[i]+mid-1)/mid;
            }
            if(sum<=threshold)
                r=mid;
            else
                l = mid+1;
        }
        return l;
    }
};