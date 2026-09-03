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