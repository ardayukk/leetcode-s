class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        vector<int> res(n);
        leftSum[0] = 0;
        rightSum[n - 1] = 0;
        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[n - i - 1] = rightSum[n - i] + nums[n - i];
        }
        for(int i = 0; i < n; i++){
            res[i] = abs(leftSum[i] - rightSum[i]);
        }
        return res;

    }
};