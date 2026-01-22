class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int tot = 0;

        while (!isNonDecreasing(nums)) {

            int k = 0;
            int bestSum = nums[0] + nums[1];

            for (int i = 1; i < (int)nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < bestSum) {
                    bestSum = s;
                    k = i;
                }
            }
            nums[k] = nums[k] + nums[k + 1];
            nums.erase(nums.begin() + (k + 1));

            tot++;
        }

        return tot;
    }

private:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};
