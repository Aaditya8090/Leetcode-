class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m = nums2.size();

        vector<vector<int>>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int i=0; i<min(n, k); i++){
            pq.push({nums1[i]+nums2[0], i, 0});
        } 

        while(k>0 && !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ans.push_back({nums1[curr[1]], nums2[curr[2]]});

            if(curr[2]+1 < m)
                pq.push({nums1[curr[1]]+nums2[curr[2]+1], curr[1], curr[2]+1});
            
            k--;
        }
        return ans;
    }
};