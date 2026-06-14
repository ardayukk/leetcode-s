class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(auto& w: words){
            int a = 0;
            for(auto& c: w){
                a += weights[(c - 'a')];
            }
            a %= 26;
            char z = 'z' - a;
            s += z;
        }
        return s;
    }
};