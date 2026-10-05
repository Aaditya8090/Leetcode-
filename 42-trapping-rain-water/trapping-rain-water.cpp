class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();

    //     int leftMax= 0, water=0;
    //     vector<int>rightMax(n, 0);
    //     rightMax[n-1] = height[n-1];

    //     for(int i=n-2; i>=0; i--)
    //         rightMax[i] = max(height[i], rightMax[i+1]);

    //     for(int i=0; i<n; i++){
    //         leftMax = max(leftMax, height[i]);
    //         water += min(leftMax, rightMax[i]) - height[i];
    //     }
    //     return water;
    // }


    // Approach 2 using monotonic stack
    int trap(vector<int>& height) {
        int n = height.size();

        stack<int>st;
        int water = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top();
                st.pop();

                if(st.empty())
                    break;

                int left = st.top();
                int width = i-left-1;

                int boundedWater = (min(height[left], height[i])-height[mid])*width;

                water += boundedWater;
            }
            st.push(i);
        }
        return water;
    }
};
