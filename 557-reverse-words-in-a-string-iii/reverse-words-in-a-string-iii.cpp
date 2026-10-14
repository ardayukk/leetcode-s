class Solution {
public:
    string reverseWords(string s) {
        size_t start = 0;
        size_t pos;

        while ((pos = s.find(' ', start)) != string::npos) {
            reverse(s.begin() + start, s.begin() + pos);
            start = pos + 1;
        }

        reverse(s.begin() + start, s.end());

        return s;
    }
};