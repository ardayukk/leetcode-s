class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int a = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    a += 4;
                    if(i > 0 && grid[i - 1][j]) a -= 2;
                    if(j > 0 && grid[i][j - 1]) a -= 2;
                }
            }
        }
        return a;
    }
};