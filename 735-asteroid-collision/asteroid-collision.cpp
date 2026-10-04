class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();

        vector<int>st;  // using vector as stack
        for(int i=0; i<n; i++){
            bool destroyed = false;
            while(!st.empty() && st.back() > 0 && ast[i]<0){
                if(abs(ast[i]) > st.back()){
                    st.pop_back();
                    continue;
                }else if(abs(ast[i]) == st.back()){
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            if(!destroyed)
                st.push_back(ast[i]);
        }
        return st;
    }
};