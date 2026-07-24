class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        constexpr int LIMIT = 2048;

        vector<bool> pairXor(LIMIT, false);
        vector<bool> tripletXor(LIMIT, false);

        for (int x : nums) {
            for (int y : nums) {
                pairXor[x ^ y] = true;
            }
        }

        for (int xy = 0; xy < LIMIT; xy++) {
            if (!pairXor[xy]) continue;

            for (int z : nums) {
                tripletXor[xy ^ z] = true;
            }
        }

        return count(tripletXor.begin(), tripletXor.end(), true);
    }
};