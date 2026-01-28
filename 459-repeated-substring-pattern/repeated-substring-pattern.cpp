class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string substr = "";
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            substr += s[i];

            // length of s must be divisible by length of substring
            if (n % substr.size() != 0) 
                continue;

            string temp = "";
            for (int j = 0; j < n; j += substr.size()) {
                temp += substr;
            }

            if (temp == s) {
                return true;
            }
        }
        return false;
    }
};
