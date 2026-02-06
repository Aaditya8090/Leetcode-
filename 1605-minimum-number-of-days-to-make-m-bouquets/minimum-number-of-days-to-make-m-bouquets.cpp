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
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans= -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(good(bloomDay, m, k, mid)){
                ans = mid;
                r = mid-1;
            }else
                l = mid+1;
        }
        return ans;
    }   
};