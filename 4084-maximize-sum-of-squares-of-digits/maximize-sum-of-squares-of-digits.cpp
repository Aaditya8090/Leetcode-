class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int dig = (sum/num);
        if(dig>9 || sum > num*9 )
            return ans;
        if(sum<10){
            string s(num-1,'0');
            ans += to_string(sum)+s;
            return ans;
        }
        if(num>1){
            int d = sum/9;
            string t(d, '9');
            ans += t;
            if(num-d > 0)
                ans += to_string(sum%9);
            if(num-d-1>0){
                string u(num-d-1, '0');
                ans += u;
            }
        }
        return ans;
    }
};