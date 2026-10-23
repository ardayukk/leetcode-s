class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int zero = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero = i;
        }

        bool inc = true, dec = true;

        for(int i = 0; i < n; i++){
            if((nums[i] + 1) % n != nums[(i + 1) % n])
                inc = false;

            if((nums[i] - 1 + n) % n != nums[(i + 1) % n])
                dec = false;
        }

        int ans = INT_MAX;

        if(inc){
            ans = min(ans, min(zero, n - zero + 2));
        }

        if(dec){
            ans = min(ans, 1 + min((zero + 1) % n, n - zero - 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};