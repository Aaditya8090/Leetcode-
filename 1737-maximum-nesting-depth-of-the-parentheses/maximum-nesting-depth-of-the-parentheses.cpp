class Solution {
public:
    int maxDepth(string s) {
        int cnt=0, depth=0;
        for(char c: s){
            if(c == '('){
                cnt++;
                depth = max(depth, cnt);
            }else if(c == ')'){
                cnt--;
            }
        }
        return depth;
    }
};