class Solution {
public:
    int reverseBits(int n) {
        int val = 0, i=0;
        long long b=1;

        while(i++<31)
            b*=2;
        
        while(n>0){
            val+= b*(n%2);
            b /= 2;
            n /= 2;
        }
        return val;
    }
};