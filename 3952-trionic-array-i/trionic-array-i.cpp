class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = 0;
        int sz = nums.size();

        // Phase 1: strictly increasing
        while (n < sz - 1 && nums[n] < nums[n + 1]) {
            n++;
        }
        if (n == 0 || n == sz - 1) return false;

        // Phase 2: strictly decreasing
        int start2 = n;
        while (n < sz - 1 && nums[n] > nums[n + 1]) {
            n++;
        }
        if (n == start2 || n == sz - 1) return false;

        // Phase 3: strictly increasing
        while (n < sz - 1 && nums[n] < nums[n + 1]) {
            n++;
        }

        return n == sz - 1;
    }
};
