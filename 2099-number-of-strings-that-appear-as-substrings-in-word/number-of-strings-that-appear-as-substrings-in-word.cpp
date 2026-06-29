class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c = 0;
        for(int i = 0; i < patterns.size();i++){
            c += (word.find(patterns[i]) != string::npos);
        }
        return c;
    }
};