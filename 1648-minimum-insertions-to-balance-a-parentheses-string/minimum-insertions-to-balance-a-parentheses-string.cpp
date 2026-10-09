class Solution {
public:
    int minInsertions(string s) { 
        stack<int>st; int ans=0, hit=0, n = s.size();
        for(int i=0; i<=n; i++){
            if(hit==2){
                if(!st.empty())
                    st.pop();
                else
                    ans++;
                hit=0;
            }

            if(i==n)continue;

            if(s[i] == '('){
                if(hit > 0){
                    hit=0;
                    if(!st.empty()){
                        st.pop();
                        ans++;
                    }else{
                        ans += 2;
                    }
                }
                st.push(s[i]);
            }else{
                hit++;
            }
        }

        if(st.empty()){
            return hit==0? ans: ans+2;
        }else{
            return hit==0? ans+st.size()*2: ans+st.size()*2-hit;
        }
    }
};