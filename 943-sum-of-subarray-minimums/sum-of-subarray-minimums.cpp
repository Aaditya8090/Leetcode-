class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int>st;
        int ans=0, MOD = 1e9+7;
        for(int i=0; i<=n; i++){
            int curr = (i==n) ? 0 : arr[i];
            while(!st.empty() && curr < arr[st.top()]){
                int curr = st.top();
                st.pop();
                int prev_smaller = st.empty() ? -1 : st.top();
                int next_smaller = i;
                ans = (ans + ((curr-prev_smaller)*(next_smaller-curr))*1ll*arr[curr])%MOD;
            }
            st.push(i);
        }

        return ans;
    }
};