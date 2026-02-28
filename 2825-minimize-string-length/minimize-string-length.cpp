class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> v;
        for(auto c: s) v.insert(c);
        return v.size();

    }
};