//(TC) O(1),
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //from this min(x2, xCenter) i can check which side my circle lie ether left side of rectangle or right side
        int nearest_x = max(x1, min(x2, xCenter));
        int nearest_y = max(y1, min(y2, yCenter));
        
        int dist_x = nearest_x - xCenter;
        int dist_y = nearest_y - yCenter;
        // by pythagoras theorem take the third line and we can find the distance
        
        return dist_x * dist_x + dist_y * dist_y <= radius * radius;
    }
};

// By using Euclidean distance
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the nearest point on the rectangle to the circle's center
        double nearest_x = max(x1, min(x2, xCenter));
        double nearest_y = max(y1, min(y2, yCenter));
        
        // Calculate the Euclidean distance
        double distance = sqrt((nearest_x - xCenter) * (nearest_x - xCenter) + (nearest_y - yCenter) * (nearest_y - yCenter));
        
        return distance <= radius;
    }
};
