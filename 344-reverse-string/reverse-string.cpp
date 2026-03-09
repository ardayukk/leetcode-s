class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        char t;
        for(int i = 0; i < n/2; i++){
            t = s[n - i - 1];
            s[n- i - 1] = s[i];
            s[i] = t;
        }
        return;
    }
};