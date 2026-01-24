class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxn = INT_MIN;
        int s = nums.size() / 2;
        int n = s * 2;
        for(int i = 0; i < s; i++){
            int curr = nums[i] + nums[n - i - 1];
            maxn = max(curr, maxn);
        }
        return maxn;

    }
};