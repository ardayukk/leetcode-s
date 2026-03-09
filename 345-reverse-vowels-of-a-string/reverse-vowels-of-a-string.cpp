class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        char t;
        vector<char> newVec;
        for(int i = 0; i < n; i++){
            if(isvowel(s[i])) newVec.push_back(s[i]);
        }
        int k = newVec.size();
        for(int i = 0; i < k/2; i++){
            t = newVec[k - i - 1];
            newVec[k - i - 1] = newVec[i];
            newVec[i] = t;
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            if(isvowel(s[i])) s[i] = newVec[j++];
        }
        return s;
    }
    bool isvowel(char c)
    {
        if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') return true;
        return false;
    }
};