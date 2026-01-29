class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        int n = nums.size();
        int maxn = -1;
        int maxi = -1;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] % 2 == 0){
                freq[nums[i]]++;
                maxn = max(freq[nums[i]], maxn);
                if(maxn == freq[nums[i]]){
                    maxi = nums[i];
                }
            }
        }
        return maxi;
    }
};