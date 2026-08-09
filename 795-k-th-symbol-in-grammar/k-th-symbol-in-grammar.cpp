class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1)
            return 0;
        
        int mid = pow(2, n-2);

        if(k<=mid)
            return kthGrammar(n-1, k);
        else
            return !kthGrammar(n-1, k-mid);
    }
};

// pattern
// N=1    0
// N=2    0 | 1
// N=3    0   1 | 1  0
// N=4    0   1   1  0 | 1  0  0  1

// first half is same as prev half
// second half is opposite/complement of first half 