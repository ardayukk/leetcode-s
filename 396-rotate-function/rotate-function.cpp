class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int tots = 0;
        for(auto& n:nums){
            tots += n;
        }

        int maxn = 0;
        int curr = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            maxn += (i * nums[i]);
        }

        curr = maxn;

        for(int i = 1; i < n; i++){
            curr -= (nums[n - i] * n);
            curr += tots;
            maxn = max(maxn, curr);
        }
        return maxn;
    }
};