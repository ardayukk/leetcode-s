class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            int maxn = *max_element(nums.begin(), nums.begin() + i);
            int minn = *min_element(nums.begin() + i, nums.end());

            if(maxn - minn <= k){
                return i;
            }  
        }
        return -1;
    }
};