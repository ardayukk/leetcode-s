#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> v;
        for (char c : s) {
            if (!v.empty() && ((v.back() == '{' && c == '}') || 
                               (v.back() == '(' && c == ')') || 
                               (v.back() == '[' && c == ']'))) {
                v.pop_back();
            } else {
                v.push_back(c);
            }
        }
        return v.empty();
    }
};
