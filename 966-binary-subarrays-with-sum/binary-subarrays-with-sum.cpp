class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // int cnt=0, sum=0, l=0;
        // for(int r=0; r<n; r++){
        //     sum += nums[r];
        //     while(l<r && sum >= goal){
        //         sum -= nums[l++];
        //     }

        //     if(sum == goal)
        //         cnt++;
        //     else{
        //         if(l>0){
        //             l--
        //             sum -= nums[l];

        //         }
        //     }
        // }
        // return cnt;

    
        int curr = 0, cnt=0;
        unordered_map<int, int>mp;
        mp[0]++;

        for(int i=0; i<n; i++){
            curr += nums[i];
            if(mp.find(curr-goal) != mp.end()){
                cnt += mp[curr-goal];
            }
            mp[curr]++;
        }
        return cnt;
    }
};