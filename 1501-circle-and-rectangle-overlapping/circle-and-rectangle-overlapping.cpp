#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the point (nearestX, nearestY) inside or on the rectangle boundary
        // that is closest to the circle's center (xCenter, yCenter)
        int nearestX = std::max(x1, std::min(xCenter, x2));
        int nearestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate dx and dy distances
        int dx = nearestX - xCenter;
        int dy = nearestY - yCenter;
        
        // Compare squared distance with squared radius to avoid floating-point errors
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};