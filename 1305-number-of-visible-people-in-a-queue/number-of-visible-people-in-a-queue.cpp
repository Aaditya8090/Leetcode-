class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        stack<int>st;
        vector<int>ans(n,0);

        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(!st.empty() && curr > heights[st.top()]){
                st.pop();
                ans[i]++;
            }

            if(!st.empty())
                ans[i]++;

            st.push(i);
        }
        return ans;
    }
};
