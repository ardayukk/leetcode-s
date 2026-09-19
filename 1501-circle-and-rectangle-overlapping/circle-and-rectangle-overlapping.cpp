class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    
        double closestX = std::clamp(
            static_cast<double>(xCenter),
            static_cast<double>(x1),
            static_cast<double>(x2)
        );

        double closestY = std::clamp(
            static_cast<double>(yCenter),
            static_cast<double>(y1),
            static_cast<double>(y2)
        );

        double dx = static_cast<double>(xCenter) - closestX;
        double dy = static_cast<double>(yCenter) - closestY;

        return dx * dx + dy * dy <=
            static_cast<double>(radius) * radius;
        }
};