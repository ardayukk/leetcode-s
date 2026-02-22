class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vs;
        int n = nums.size();
        if(n == 0) return vs;
        int begin = nums[0];
        for(int i = 0; i < n - 1; i++){
            if(nums[i] != nums[i + 1] - 1){
                if(begin != nums[i]){
                    vs.push_back(to_string(begin) + "->" + to_string(nums[i]));
                    begin = nums[i + 1];
                }
                else{
                    vs.push_back(to_string(nums[i]));
                    begin = nums[i + 1];
                }
            }
        }
        if(begin != nums[n - 1]){
            vs.push_back(to_string(begin) + "->" + to_string(nums[n - 1]));
        }
        else{
            vs.push_back(to_string(nums[n - 1]));
        }
        return vs;
    }
};