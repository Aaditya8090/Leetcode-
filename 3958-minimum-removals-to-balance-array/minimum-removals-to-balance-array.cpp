class Solution {
public:
    int good(vector<int>&a, int left, int k){
        int n=a.size();
        int l = left, r=n-1;
        int val = a[left], ans=left;
       
        while(l<=r){
            int mid = l + (r-l)/2;
            long v = val*1ll*k;
            if(v >= a[mid]){
                ans=mid;
                l=mid+1;
            }else 
                r = mid-1;
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, good(nums, i, k)-i+1);
        }
        return n-ans;
    }
};