class Solution {
public:
    int minInsertions(string s) { 
        stack<int>st; int ans=0, hit=0, cnt=0, n = s.size();
        for(int i=0; i<=n; i++){
            if(hit==2){
                if(cnt>0)
                    cnt--;
                else
                    ans++;
                hit=0;
            }

            if(i==n)continue;

            if(s[i] == '('){
                if(hit > 0){
                    hit=0;
                    if(cnt>0){
                        cnt--;
                        ans++;
                    }else{
                        ans += 2;
                    }
                }
                cnt++;
            }else{
                hit++;
            }
        }

        if(cnt==0){
            return hit==0 ? ans : ans+2;
        }else{
            return hit==0? ans + cnt*2: ans + cnt*2 - hit;
        }
    }
};