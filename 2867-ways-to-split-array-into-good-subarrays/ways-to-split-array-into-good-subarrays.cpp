class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1000000007;
        int n = nums.size();
        int i = 0;
        while(i < n && nums[i] != 1){
            i++;
        }
        if(i == n) return 0;
        long long cnt = 1;
        for(int j = i + 1; j < n; j++){
            if(nums[j] == 1){
                cnt *= (j - i);
                cnt %= mod;
                i = j;
            }
        }

        if(cnt == 0) return 1;
        return (int)cnt;
        
    }
};