class Solution {
public:
    bool good(vector<int>a, int k, int h){
        int n=a.size();long long cnt=0;
        for(int i=0; i<n; i++){
            cnt += (a[i]+k-1)/k;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans=r;
        while(l<=r){
            int mid = (l+r)/2;
            if(good(piles, mid, h)){
                ans = mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};