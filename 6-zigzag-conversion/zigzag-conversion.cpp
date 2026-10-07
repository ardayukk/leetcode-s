class Solution {
public:
    string compute(vector<vector<char>>& vec){
        string s = "";
        for(auto& v: vec){
            // for(auto& c: v){
            //     cout << c;
            // }
            // cout << endl;
            for(auto& c:v){
                s.push_back(c);
            }
        }
        return s;
    }
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < numRows; j++){
                if(i == s.size()){
                    return compute(v);
                }
                v[j].push_back(s[i]);
                i++;
            }
            for(int j = 1; j < numRows - 1; j++){
                if(i == s.size()){
                    return compute(v);
                }
                v[numRows - j - 1].push_back(s[i]);
                i++;
            }
            i--;
        }
        return compute(v);
    }
};