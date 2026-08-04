class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> v;

        auto it = s.begin();
        auto nextIt = next(it);

        while (nextIt != s.end()) {
            for (int x = *it + 1; x < *nextIt; x++) {
                v.push_back(x);
            }

            ++it;
            ++nextIt;
        }

        return v;
    }
};