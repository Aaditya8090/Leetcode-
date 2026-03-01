class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            if(st.count(s[i])){
                s.pop_back();
            }else
                break;
        }
        return s;
    }
};