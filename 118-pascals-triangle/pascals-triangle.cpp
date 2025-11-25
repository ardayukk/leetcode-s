class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> v(numRows);
        for(int i = 0; i < numRows; i++){
            vector<int> v1(i + 1);
            if(i == 0){
                v1[0] = 1;
            }
            else{
                for(int j = 0; j < i + 1;j++){
                    if(j == 0){
                        v1[j] = v[i-1][j];
                    }
                    else if(j == i){
                        v1[j] = v[i-1][j-1];
                    }
                    else{
                        v1[j] = v[i-1][j-1] + v[i-1][j];
                    }
                }
            }
            v[i] = v1;
        }
        return v;
    }
};