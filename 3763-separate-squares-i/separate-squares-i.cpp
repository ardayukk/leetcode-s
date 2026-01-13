class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double minY = 1e18;
        double maxY = -1e18;

        for (auto& a : squares) {
            double bottom = a[1];
            double top = a[1] + a[2];
            minY = min(minY, bottom);
            maxY = max(maxY, top);
        }

        double low = minY;
        double high = maxY;

        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            if (areaDifference(mid, squares) > 0) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return (low + high) / 2.0;
    }

    double areaDifference(double y, vector<vector<int>>& squares) {
        double area_above = 0.0;
        double area_below = 0.0;

        for (auto& a : squares) {
            double bottom = a[1];
            double top    = a[1] + a[2];
            double side   = a[2];

            if (top <= y) {
                area_below += side * side;
            }
            else if (bottom >= y) {
                area_above += side * side;
            }
            else {
                double below_height = y - bottom;
                double above_height = top - y;

                area_below += below_height * side;
                area_above += above_height * side;
            }
        }

        return area_above - area_below;
    }
};
