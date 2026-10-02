class Solution {
public:
    // sliding window
    long long atmost(vector<int>&nums, int k){
        if(k<0)return 0;

        int l=0, n=nums.size(), sum=0;
        long long cnt=0;

        for(int r=0; r<n; r++){
            sum += nums[r];

            while(sum > k){
                sum -= nums[l];
                l++;
            }
            
            cnt += (r-l+1);
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        // Trick:  Exactly with Sum K = At most with sum K - Atmost with sum K-1
        return atmost(nums, goal) - atmost(nums, goal-1);

        // hashmap approach
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