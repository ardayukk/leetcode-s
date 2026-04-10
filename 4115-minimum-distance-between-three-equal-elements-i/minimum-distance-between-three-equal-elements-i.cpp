class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int INF = 1e9;
        int ans = INF;

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);

            int m = pos[nums[i]].size();
            if (m >= 3) {
                ans = min(ans, 2 * (i - pos[nums[i]][m - 3]));
            }
        }

        return ans == INF ? -1 : ans;
    }
};