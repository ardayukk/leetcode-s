class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int** dp = new int*[s.length()];
        for(int i = 0; i < s.length(); i++){
            int* temp = new int[s.length()];
            dp[i] = temp;
        }
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int length = 2; length <= s.length(); length++){
            for(int i = 0; i + length -1 < s.length(); i++){
                int j = i + length - 1;
                if(length == 2 && s[i] == s[j]){
                    dp[i][j] = 2;
                }
                else if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j - 1]);
                }
            }
        }

    return dp[0][s.length() - 1];
    }
};