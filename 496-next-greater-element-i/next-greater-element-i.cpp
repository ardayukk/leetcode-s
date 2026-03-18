class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            int curr = nums1[i];
            int j = 0;
            for(; j < nums2.size(); j++){
                if(curr == nums2[j]) break;
            }
            bool flag = false;
            for(; j < nums2.size(); j++){
                if(curr < nums2[j]) {
                    ans.push_back(nums2[j]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};