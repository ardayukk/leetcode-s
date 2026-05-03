class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.size() + 1; i++){
            if(s == goal) return true;

            char c = s[0];
            s = s.substr(1);
            s.push_back(c);
        }   
        return false;
    }
};