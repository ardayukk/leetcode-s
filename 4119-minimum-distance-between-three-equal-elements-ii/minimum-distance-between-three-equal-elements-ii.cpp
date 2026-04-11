class Solution {
public:
    using ll = long long;
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;

        unordered_map<int,vector<int>> um;

        for(int i = 0; i < nums.size(); i++){
            um[nums[i]].push_back(i);

            int n = um[nums[i]].size();
            if(n >= 3){
                ans = min(ans, 2 * (um[nums[i]][n-1] - um[nums[i]][n-3]));
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;

    }
};