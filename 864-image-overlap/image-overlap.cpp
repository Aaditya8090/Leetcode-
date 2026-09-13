class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vec1, vec2;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) vec1.push_back({r, c});
                if (img2[r][c] == 1) vec2.push_back({r, c});
            }
        }

        unordered_map<int, int> count;
        int max_overlap = 0;

        for (const auto& p1 : vec1) {
            for (const auto& p2 : vec2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                int key = (dr + 30) * 100 + (dc + 30);
                
                count[key]++;
                max_overlap = max(max_overlap, count[key]);
            }
        }

        return max_overlap;
    }
};