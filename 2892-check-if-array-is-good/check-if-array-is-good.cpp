class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        vector<int> base(n);
        for(int i = 0; i < n; i++){
            base[i] = (i + 1);
        }
        base[n - 1]--;

        for(int i = 0; i < n; i++){
            if(base[i] != nums[i]) return false;
        }

        return true;
    }
};