class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> vec(k,0);
        vector<vector<long long>> dp(nums.size(), vector<long long>(k, 0));

        int init = nums[0];
        init %= k;

        dp[0][init]++;

        for(int i = 1; i < nums.size();i++){
            int curr = nums[i] % k;
        
            for(int j = 0; j < k; j++){
                int currs = curr * j;
                currs %= k;
                dp[i][currs] += dp[i-1][j];
            }
            dp[i][curr]++;
        }

        for(int i = 0; i < nums.size(); i++){

            for(int j = 0; j < k; j++){
                vec[j] += dp[i][j];
            }
        }

        return vec;
    }
};