class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        int reach = 0;

        for(int i = 1; i < n; i++){
            int add = i - minJump;

            if(add >= 0 && dp[add]){
                reach++;
            }

            int subs = i - maxJump - 1;

            if(subs >= 0 && dp[subs]){
                reach--;
            }

            if(reach > 0 && s[i] == '0'){
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};