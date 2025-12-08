class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // 1. Sort by finish time
        sort(points.begin(), points.end(),
             [](auto &a, auto &b) { return a[1] < b[1]; });
        int count = 0;
        for(int i = 0; i < points.size(); i++){
            int curr = points[i][1];
            while(points[i][0] <= curr){
                i++;
                if(i >= points.size()){
                    break;
                }
            }
            i--;
            count++;
        }
        return count;
    }
};