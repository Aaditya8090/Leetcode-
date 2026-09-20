class Solution {
public:
    int reverseDegree(string s) {
        int arr[130];
        int value = 26;
        for(int i=97; i<123; i++)
            arr[i] = value-- ;

        int degree = 0;
        for(int i=0; i<s.size(); i++){
            degree += (i+1) * arr[s[i]];
        }

        return degree;
    }

    
};