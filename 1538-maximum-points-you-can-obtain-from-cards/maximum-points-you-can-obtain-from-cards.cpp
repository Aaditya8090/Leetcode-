class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if(k==n)
            return sum;

        int curr=0, mn=INT_MAX;
        k = n-k;

        for(int i=0; i<n; i++){
            curr += cardPoints[i];

            if(i >= k){
                curr -= cardPoints[i-k];
            }

            if(i >= k-1){
                mn = min(curr, mn);
            }
        }

        return sum-mn;
    }
};