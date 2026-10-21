class Solution {
public:
    bool check(string &s){
        int n = s.size();
        bool flag=true;
        
        for(int i=0; i<n-1; i++){
            if(s[i]>s[i+1]){
                flag = false;
                break;
            }
        }
        return flag;
    }
    
    bool check1(string s){
        sort(s.begin()+1, s.end());
        sort(s.begin(), s.end()-1);
        return check(s);
    }
    
    bool check2(string s){
        sort(s.begin(), s.end()-1);
        sort(s.begin()+1, s.end());
        return check(s);
    }
    
    int minOperations(string s) {
        int n = s.size();
        if(n==1)
            return 0;
        if(n==2){
            if(s[0]<=s[1])
                return 0;
            else
                return -1;
        }
        
        if(check(s))
            return 0;
        
        char mnc = 'z', mxc='a'; 
        for(int i=0; i<n; i++){
            if(mnc > s[i])
                mnc = s[i];
            
            if(s[i]>mxc)
                mxc = s[i];
        }
        
        int ans=0;
        if(s[0] == mnc || s[n-1]==mxc)
            return 1;
        else
            ans= 2;
     
        if(check1(s) || check2(s))
            return ans;
        return ans+1;
    }
};