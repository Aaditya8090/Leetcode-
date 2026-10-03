class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++)
            mp[nums1[i]] = i;

        stack<int>st;
        vector<int>ans(n, -1);
        n = nums2.size();

        for(int i=0; i<n; i++){
            int curr = nums2[i];
            while(!st.empty() && curr > nums2[st.top()]){
                if(mp.find(nums2[st.top()]) != mp.end())
                    ans[mp[nums2[st.top()]]] = curr;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};