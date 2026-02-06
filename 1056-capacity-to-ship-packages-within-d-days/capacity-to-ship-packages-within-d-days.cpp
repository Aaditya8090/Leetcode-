class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
    
        int l= *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans=l;
        while(l<=r){
            int mid = l + (r-l)/2;
            int curr=0, sum=0;
            for(int i=0; i<n; i++){
                sum += weights[i];
                if(sum>mid){
                    sum=weights[i];
                    curr++;
                }                   
            }
            curr++;
            if(curr<=days){
                ans = mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};