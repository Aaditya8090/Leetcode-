class Solution {
public:
    vector<int>par;
    int find(int x){
        if(par[x] == x)
            return x;
        
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y)
            return ;
        
        if(par_x < par_y){
            par[par_y] = par_x;
        }else{
            par[par_x] = par_y;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26);
        for(int i=0; i<26; i++)
            par[i] = i;
        
        for(int i=0; i<s1.size(); i++){
            merge(s1[i]-'a', s2[i]-'a');
        }

        string ans = "";
        for(char c: baseStr){
            ans.push_back(find(c-'a')+'a');
        }
        return ans;
    }
};