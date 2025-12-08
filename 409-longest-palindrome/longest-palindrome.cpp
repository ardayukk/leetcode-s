class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128,0);
        for(char c: s){
            cnt[c]++;
        }
        int c = 0;
        bool hasOdd = false;
        for(int x: cnt){
            if(x % 2 == 0){
                c+= x;
            }
            else{
                c += x - 1;
                hasOdd = true;
            }
        }
        if(hasOdd){
            c++;
        }
        return c;
    }
};