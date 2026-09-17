class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i=0, j=0;
        int currSum = 0;

        vector<int>minBestLen(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int ans = INT_MAX;

        while(j<n){
            currSum += arr[j];

            while(i<j && currSum > target){
                currSum -= arr[i++];
            }

            if(currSum == target){
                int len = j-i+1;

                if(i>0 && minBestLen[i-1] != INT_MAX){
                    ans = min(ans, len + minBestLen[i-1]);
                }
                bestMinLen = min(bestMinLen, len);
            }

            minBestLen[j] = bestMinLen;
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};