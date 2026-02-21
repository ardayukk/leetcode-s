class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) return false;
        unordered_map<char, char> um1;
        unordered_map<char, char> um2;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(um1.count(c)){
                if(um1[c] != t[i]){
                    return false;
                }
            }
            else{
                um1[c] = t[i];
            }
            c = t[i];
            if(um2.count(c)){
                if(um2[c] != s[i]){
                    return false;
                }
            }
            else{
                um2[c] = s[i];
            }

        }
        return true;
    }
};