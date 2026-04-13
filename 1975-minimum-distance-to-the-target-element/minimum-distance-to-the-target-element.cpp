class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int f = start + i;
            int s = start - i;
            if(f <= n - 1 && nums[f] == target) return i;
            if(s >= 0 && nums[s] == target) return i;
        }
        return 0;
    }
};