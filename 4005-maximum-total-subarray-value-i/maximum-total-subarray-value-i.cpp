class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxn = INT_MIN;
        long long minn = INT_MAX;

        for(auto& n: nums){
            if(n > maxn) maxn = n;
            if(n < minn) minn = n;
        }    

        return (maxn - minn) * k;
    }
};