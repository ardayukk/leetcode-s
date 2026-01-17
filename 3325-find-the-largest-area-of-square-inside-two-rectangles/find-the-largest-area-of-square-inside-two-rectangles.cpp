class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxl = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n;j++){
                maxl = max(maxl, areaBetween(bottomLeft[i][0],
                                            topRight[i][0],
                                            bottomLeft[i][1],
                                            topRight[i][1],
                                            bottomLeft[j][0],
                                            topRight[j][0],
                                            bottomLeft[j][1],
                                            topRight[j][1]));
            }
        }
        return maxl;
    }
    long long areaBetween(int x1, int x2, int y1, int y2,
                      int x3, int x4, int y3, int y4) {

    int xLength = max(0, min(x2, x4) - max(x1, x3));
    int yLength = max(0, min(y2, y4) - max(y1, y3));

    long long side = min(xLength, yLength);
    return side * side;
}

};