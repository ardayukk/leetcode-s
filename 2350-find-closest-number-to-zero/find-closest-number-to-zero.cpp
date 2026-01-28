class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(abs(nums[i]) < abs(nums[j])){
                j = i;
            }
            if(abs(nums[i]) == abs(nums[j])){
                if(nums[i] > nums[j]){
                    j = i;
                }
            }
        }
        return nums[j];
    }
};