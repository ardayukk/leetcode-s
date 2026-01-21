class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,-1);
            for(int i{}; i < n; i++){
                int x = nums[i];
                for (int k = 30; k >= 0; k--) {

                    // bit k must be 1 in x
                    if (((x >> k) & 1) == 0) continue;

                    // lower k bits must all be 1
                    int mask = (1 << k) - 1;
                    if ((x & mask) != mask) continue;

                    int cand = x - (1 << k);

                    result[i] = cand;
                    break;
                }
            }
        return result;
    }
};