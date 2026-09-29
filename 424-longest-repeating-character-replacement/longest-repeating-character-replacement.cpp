class Solution {
public:
    int getMx(unordered_map<char, int>& mp) {
        int mx = 0;
        for (auto& [a, b] : mp)
            mx = max(mx, b);

        return mx;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0, mxFreq = 0, ans = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            mxFreq = max(mxFreq, mp[s[r]]);

            while ((r - l + 1) - mxFreq > k) {
                mp[s[l]]--;
                l++;
                mxFreq = getMx(mp);
            }

            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};