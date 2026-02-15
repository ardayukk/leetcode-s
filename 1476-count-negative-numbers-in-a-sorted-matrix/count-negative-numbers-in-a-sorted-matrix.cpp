class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i{}; i < grid.size(); i++){
            for(int j{}; j < grid[0].size(); j++){
                if(grid[i][j] < 0){
                    count++;
                }
            }
        }
        return count;
    }
};