class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
        if (n <= 1) return 0;
        
        int inc_drops = 0;
        int dec_drops = 0;
        int pos = -1;
        
        // Find the index of 0 and count cyclic structural breaks
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) pos = i;
            
            if (nums[i] > nums[(i + 1) % n]) inc_drops++;
            if (nums[i] < nums[(i + 1) % n]) dec_drops++;
        }
        
        int ans = -1;
        
        // 1. Evaluate if it's a shifted increasing sequence
        if (inc_drops <= 1) {
            int cost_left_rotates = pos;
            int cost_right_rotates = (pos == 0) ? 0 : (n - pos + 2);
            
            int min_cost = min(cost_left_rotates, cost_right_rotates);
            ans = (ans == -1) ? min_cost : min(ans, min_cost);
        }
        
        // 2. Evaluate if it's a shifted decreasing sequence
        if (dec_drops <= 1) {
            int cost_reverse_then_rotate = n - pos;
            int cost_rotate_then_reverse = pos + 2;
            
            int min_cost = min(cost_reverse_then_rotate, cost_rotate_then_reverse);
            ans = (ans == -1) ? min_cost : min(ans, min_cost);
        }
        
        return ans;
        
        // int n = nums.size();
        // if(n==1)return 0;
        // int mn = *min_element(nums.begin(), nums.end());
        // vector<bool>vis(n, false);
        // int ans=0;
        
        // for(int i=0; i<n; i++){
        //     if(vis[i])continue;
            
        //     int cs=0, curr=i;
            
        //     while(!vis[curr]){
        //         vis[curr] = true;
        //         int tIdx = nums[curr]-mn;
        //         curr = tIdx;
        //         cs++;
        //     }
        //     if(cs>1)
        //         ans += (cs-1);
        //     }
        
        // return ans;
        // bool isPos = true; int idx=-1;
        // bool isInc=true, isDec=true;

        // for(int i=0; i<n-1; i++){
        //     if(nums[i+1]<nums[i]){
        //         isInc=false;
        //     }
        // }
        // if(isInc)return 0;

        // int mn = *min_element(nums.begin(), nums.end());
        // for(int i=0; i<n; i++){
        //     if(nums[i]==mn){
        //         idx=i;
        //         break;
        //     }
        // }
        // vector<int>num2(nums.begin(), nums.begin()+idx+1);
        // copy(num2.begin(), num2.end(), back_inserter(nums));
        // // nums.pop_back();
        // for(int i=idx+1; i<nums.size()-1; i++){
        //     if(nums[i+1]>nums[i]){
        //         isDec=false;
        //         break;
        //     }
        // }
    
        // if(isDec)
        //     return min(idx+2, n-idx);
        // else
        //     return -1;
    }
};