class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = 0;
        int r = nums.size() - 1;

        while (p <= r) {
            int mid = p + (r - p) / 2;

            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                p = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};
