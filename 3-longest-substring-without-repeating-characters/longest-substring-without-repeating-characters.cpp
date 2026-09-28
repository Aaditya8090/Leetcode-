class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_set<char> st;
        int l = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            while (st.count(s[r])) {
                st.erase(s[l++]);
            }

            st.insert(s[r]);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};