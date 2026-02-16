class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        bool ispalindrome = true;
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - i - 1]){
                ispalindrome = false;
                break;
            }
        }   
        if(ispalindrome){
            return 1;
        }
        return 2;
    }
};