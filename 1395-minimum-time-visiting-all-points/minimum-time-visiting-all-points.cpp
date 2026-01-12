class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x;
        int y;
        x = points[0][0];
        y = points[0][1];
        int n = 0;
        for(int i = 1; i < points.size(); i++){
            while(x != points[i][0] || y != points[i][1]){
                if(points[i][0] > x){
                    x++;
                }
                else if(points[i][0] < x){
                    x--;
                }
                if(points[i][1] > y){
                    y++;
                }
                else if(points[i][1] < y){
                    y--;
                }
                n++;
            }
        }
        return n;
    }
};