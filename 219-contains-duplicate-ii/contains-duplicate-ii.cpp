class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int n = (int)nums.size();

        for (int i = 0; i < n; i++) {
            if (window.count(nums[i])) return true;

            window.insert(nums[i]);

            if ((int)window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};