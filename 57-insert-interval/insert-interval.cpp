class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());

        // vector<vector<int>>ans;
        // ans.push_back(intervals[0]);
        // for(int i=1; i<intervals.size(); i++){
        //     if(intervals[i][0] <= ans.back()[1]){
        //         vector<int>curr = ans.back();
        //         ans.pop_back();
        //         ans.push_back({curr[0], max(intervals[i][1], curr[1])});
        //     }else{
        //         ans.push_back(intervals[i]);
        //     }
        // }
        // return ans;

        // 2nd approach  O(n)
        int n = intervals.size();
        int i=0;
        vector<vector<int>>ans;
        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0]<= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};