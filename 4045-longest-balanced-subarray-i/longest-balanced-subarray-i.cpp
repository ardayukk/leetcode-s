class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            seen.reserve(n * 2);
            seen.max_load_factor(0.7f);

            int distinctEven = 0;
            int distinctOdd  = 0;

            for (int j = i; j < n; ++j) {

                // insert returns a pair:
                //   first  -> iterator to the element
                //   second -> true if insertion happened (meaning it was NOT present before)
                pair<unordered_set<int>::iterator, bool> res = seen.insert(nums[j]);

                bool inserted = res.second;
                if (inserted) { // first time we see nums[j] in this window
                    if (nums[j] % 2 == 0) distinctEven++;
                    else distinctOdd++;
                }

                if (distinctEven == distinctOdd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
