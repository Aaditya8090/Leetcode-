class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activeCount = count(begin(s), end(s), '1');

        vector<int>inactiveBlocks;
        int i=0;
        while(i<n){
            if(s[i] == '0'){
                int start=i;
                while(i<n && s[i]== '0')i++;
                inactiveBlocks.push_back(i-start);
            }else
                i++;
        }

        int maxPairSum = 0;
        for(int j=1; j<inactiveBlocks.size(); j++){
            maxPairSum = max(inactiveBlocks[j]+inactiveBlocks[j-1], maxPairSum);
        }
        return activeCount + maxPairSum;
    }
};

// for every one's see the length of left block zeroes and right block zeroes