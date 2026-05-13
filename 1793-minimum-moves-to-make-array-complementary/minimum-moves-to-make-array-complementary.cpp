class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++){
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            // Start with 2 moves for every possible target sum
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // For [low, high], only 1 move is needed instead of 2
            diff[low] -= 1;
            diff[high + 1] += 1;

            // For exact sum, 0 moves is needed instead of 1
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int current = 0;

        for(int target = 2; target <= 2 * limit; target++){
            current += diff[target];
            ans = min(ans, current);
        }

        return ans;
    }
};