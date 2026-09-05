class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>p(n), s(n);
        p[0]=nums[0];s[n-1]=nums[n-1];
        for(int i=1; i<n; i++)
            p[i] = max(p[i-1],nums[i]);
        for(int i=n-2; i>=0; i--)
            s[i] = min(s[i+1],nums[i]);
        for(int i=0; i<n; i++){
            int sc = p[i]-s[i];
            if(sc<=k)
                return i;
        }
        return -1;
    }
};