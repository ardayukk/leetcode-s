class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count0 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count0++;
            }
        }
        vector<int> ans(n,0);
        int j = 0;
        for(auto& a: nums){
            if(a != 0){
                ans[j] = a;
                j++;
            }
        }
        nums = ans;
        return;
    }
};