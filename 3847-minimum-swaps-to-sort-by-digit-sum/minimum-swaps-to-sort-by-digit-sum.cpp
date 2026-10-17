class Solution {
public:
    static int sum(int n){
        int s = 0;
        while(n>0){
            s += n%10;
            n /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>num;
        for(int i: nums){
            num.push_back(i);
        }

        sort(num.begin(), num.end(), [](int a, int b){
            int sum1 = sum(a);
            int sum2 = sum(b);
            if(sum1 != sum2)
                return sum1 < sum2;
            return a<b;
        });

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int expVal = num[i];
            int curr = nums[i];
            if(expVal == curr)
                continue;
            
            int idx = mp[expVal];

            nums[i] = expVal;
            nums[idx] = curr;

            mp[expVal] = i;
            mp[curr] = idx;
            ans++;
        }
        return ans;
    }
};