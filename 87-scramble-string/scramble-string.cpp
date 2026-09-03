class Solution {
public:
    unordered_map<string, bool>mp;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2) == 0)
            return true;
        if(s1.size() <= 1)
            return false;

        string key = s1;
        key.push_back(' ');
        key.append(s2);

        if(mp.find(key) != mp.end())
            return mp[key];

        int n = s1.size();
        
        // 1. Pruning optimization to avoid TLE
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return mp[key] = false;
        }
        
        bool flag = false;
        for(int i=1; i<n; i++){
            // swap
            bool case1 = isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i));
            // do not swap
            bool case2 = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i));

            if(case1 || case2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
};