class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> rotatedBox(m, vector<char>(n));



        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rotatedBox[j][i] = boxGrid[i][j];
            }
        }

        for(int i = 0; i < rotatedBox.size();i++){
            for(int j = 0; j < rotatedBox[i].size() / 2;j++){
                swap(rotatedBox[i][j], rotatedBox[i][n - j  - 1]);
            }
        }

        for(int i = 0; i < rotatedBox[0].size(); i++){
            for(int j = rotatedBox.size() - 1; j >= 0; j--){
                if(rotatedBox[j][i] == '.'){
                    int jcpy = j;
                    while(jcpy > -1 && rotatedBox[jcpy][i] == '.') jcpy--;
                    
                    if(jcpy == -1)continue;
                    else if(rotatedBox[jcpy][i] == '*') j = jcpy;
                    else swap(rotatedBox[jcpy][i], rotatedBox[j][i]);
                    
                }
            }
        }

        return rotatedBox;
    }

};