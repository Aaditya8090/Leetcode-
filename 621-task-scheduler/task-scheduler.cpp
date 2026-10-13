class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;

        unordered_map<char, int>mp;
        for(int t: tasks)
            mp[t]++;

        priority_queue<int>pq;
        for(auto &[a,b]: mp){
            pq.push(b);
        }

        while(!pq.empty()){
            int cycle = n+1, cnt=0;
            vector<int>tmp;
            for(int i=0; i<cycle && !pq.empty(); i++){
                tmp.push_back(pq.top()-1);
                pq.pop();
                cnt++;
            }

            for(int rem: tmp){
                if(rem>0)
                    pq.push(rem);
            }

            ans += pq.empty() ? cnt : cycle;
        }
        return ans;
    }
};