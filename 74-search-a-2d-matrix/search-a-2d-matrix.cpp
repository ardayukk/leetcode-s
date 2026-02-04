class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size() - 1;
        int p = 0;
        int r = matrix.size() - 1;
        int x = -1;
        int mid;
        while(p <= r){
            mid = p + (r - p) / 2; 
            if(matrix[mid][0] <= target && matrix[mid][n] >= target){
                x = mid;  
                break;  
            }
            else if(matrix[mid][0] > target){
                r = mid - 1;
            }
            else{
                p = mid + 1;
            }
        }
        int y = -1;
        p = 0;
        r = n;
        if(x == -1){
            return false;
        }
        while(p <= r){
            mid = p + (r - p) / 2; 
            if(matrix[x][mid] == target){
                y = mid;  
                break;  
            }
            else if(matrix[x][mid] > target){
                r = mid - 1;
            }
            else{
                p = mid + 1;
            }
        }
        if(y == -1){
            return false;
        }
        return true;
    }
};