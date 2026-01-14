class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        vector<pair<int,int>> pairs;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++)
            if(abs(nums[i] - nums[j]) <= min(nums[i] , nums[j])){
                pairs.push_back(make_pair(nums[i] , nums[j]));
            }
        }
        int curr = 0;
        for(auto& p : pairs){
            curr = max(curr, p.first ^ p.second);
        }
        return curr;
    }
};