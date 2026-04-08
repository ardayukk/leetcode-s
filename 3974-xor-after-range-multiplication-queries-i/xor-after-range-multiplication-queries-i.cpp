class Solution {
public:
    using ll = long long;
    const ll MOD = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<ll> numsll(nums.size());

        for(int i = 0; i < nums.size(); i++){
            numsll[i] = nums[i];
        }

        for(auto& v: queries){
            v[3] %= MOD;
            for(int i = v[0]; i <= v[1]; i += v[2]){
                numsll[i] *= v[3];
                numsll[i] %= MOD;
            }
        }

        ll a = numsll[0];

        for(int i = 1; i < numsll.size(); i++){
            a ^= numsll[i];
        }

        return a;
    }
};