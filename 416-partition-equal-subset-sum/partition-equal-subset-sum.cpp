class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 == 1) return false;
        int halfSum = total / 2;

        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = halfSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[halfSum];
    }
};
