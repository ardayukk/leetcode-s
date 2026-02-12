class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        } 

        for(auto a: freq){
            if(a.first > 0){
                sum += a.first;
            }
        }
        if(sum == 0){
            int maxb = INT_MIN;
            for(int i = 0; i < n; i++){
                maxb = max(maxb, nums[i]);
            }
            sum = maxb;
        }
        return sum;
    }
};