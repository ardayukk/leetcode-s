class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n >= 3){
            return pow(2, 32 - __builtin_clz(n)) ;
        }

        return n;
    }
};