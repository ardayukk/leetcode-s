class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> set;
        int n = pattern.size();int pos = 0;
        for(int i = 0; i < n; i++){
            if(pos >= s.size()) return false;
            int start = pos;
            while(pos < s.size() && s[pos] != ' ') pos++;
            string word = s.substr(start, pos - start);
            pos++;
            if(mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != word) return false;
            if(set.find(word) != set.end() && mp[pattern[i]] != word) return false;
            set.insert(word);
            mp[pattern[i]] = word;
        }
        return pos == s.size() + 1;
    }
};