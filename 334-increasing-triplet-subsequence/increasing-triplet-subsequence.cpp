class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Method 1 - Prefix/Suffix array




        
        // Method 2 - Two Pointers
        int smallest = INT_MAX, secSmallest= INT_MAX;
        for(int x: nums){
            if(x <= smallest)
                smallest = x;
            else if(x <= secSmallest)
                secSmallest = x;
            else
                return true;
        }
        return false;
    }
};