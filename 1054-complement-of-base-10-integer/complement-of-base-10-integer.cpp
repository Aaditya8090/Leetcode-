class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int base = 1, ans=0;
        while(n>0){
            int rem = n%2;
            if(rem==0)
                ans += base;
            n/=2;
            base*=2;
        }
        return ans;
    }
};