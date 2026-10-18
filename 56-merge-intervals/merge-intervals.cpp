class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans.back()[1]){
                vector<int>curr = ans.back();
                ans.pop_back();
                ans.push_back({min(curr[0], intervals[i][0]), max(curr[1], intervals[i][1])});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};