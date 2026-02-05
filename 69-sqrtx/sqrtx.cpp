class Solution {
public:
    int mySqrt(int n) {
        long long l=1, r=n, ans=n;
        while(l<=r){
            long long mid = (l+r)/2;
            if(mid*mid <= n){
                ans = mid;
                l = mid+1;
            }else
                r = mid-1;
        }
        return ans;
    }
};