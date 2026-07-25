class Solution {
public:
    int maxProduct(int n) {
        int f=0,s=0;
        while(n>0){
            int dig = n%10;
            if(dig > s){
                f = s;
                s = dig;
            }else
                f = max(f, dig);
            n=n/10;
        }
        return f*s;
    }
};