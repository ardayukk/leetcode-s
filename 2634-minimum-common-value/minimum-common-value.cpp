class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int f = 0;
        int s = 0;
        while(f < n && s < m){
            if(nums1[f] == nums2[s]) return nums1[f];

            if(nums1[f] < nums2[s]) f++;
            else s++;
        }
        return -1;
    }
};