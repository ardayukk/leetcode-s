class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1,-1};
        }
        int l = 0;
        int r = nums.size() -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] >= target){
                r = m -1;
            }
            else{
                l = m + 1;
            }
        }
        if(l < 0 || l >= nums.size()){
            return {-1, -1};
        }
        if(nums[l] != target) return {-1, -1};
        int x = l;
        while(x != nums.size() - 1 && nums[x] == target){
            x++;
        }
        if(nums[x] != target) x--;
        return{l, x};
    }
};