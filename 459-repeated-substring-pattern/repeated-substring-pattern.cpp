class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string substr = "";
        for(int i = 0; i < s.size()/2; i++){
            substr += s[i];
            string temp = "";
            for(int j = 0; j < s.size(); j += substr.size()){
                temp += substr;
            }
            if(temp == s){
                return true;
            }
        }

        return false;
    }
};