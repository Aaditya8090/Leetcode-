class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l<r){
            int mid = l + (r-l)/2;
            int sum=0;
            for(int num: nums){
                sum += (num+mid-1)/mid;
            }
            if(sum<=threshold)
                r=mid;
            else
                l = mid+1;
        }
        return l;
    }
};