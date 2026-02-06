class Solution {
public:
    bool good (vector<int>a, int tc, int k, int val){
        int cnt=0, ans=0, n=a.size();
        for(int i=0; i<n; i++){
            if(val>=a[i])
                cnt++;
            else
                cnt=0;
            
            if(cnt==k){
                ans++;
                cnt=0;
            }
        }
        return ans>= tc;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*1ll*k > n)
            return -1;
        long long l = 1;
        long long r = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans= -1;
        while(l<=r){
            long long mid = (l+r)/2;
            if(good(bloomDay, m, k, mid)){
                ans = mid;
                r = mid-1;
            }else
                l = mid+1;
        }
        return (int)ans;
    }   
};