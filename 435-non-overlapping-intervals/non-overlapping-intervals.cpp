class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //greedy problem
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[1] == b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        });

        int cnt=0, last=INT_MIN;
        for(auto i: intervals){
            if(i[0] >= last){
                cnt++;
                last = i[1];
            }
        }
        return intervals.size()-cnt;
    }
};