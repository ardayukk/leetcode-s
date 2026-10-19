class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int index = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] < target){
                index++;
            }
            else if(nums[i] == target){
                count++;
            }
        } 

        vector<int> v;
        for(int i = 0; i < count; i++){
            v.push_back(index++);
        }
        return v;
    }
};