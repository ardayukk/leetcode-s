class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> newVec(m + n);

        int k = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j])
                newVec[k++] = nums1[i++];
            else
                newVec[k++] = nums2[j++];
        }

        while(i < m) newVec[k++] = nums1[i++];
        while(j < n) newVec[k++] = nums2[j++];

        nums1 = newVec;
    }
};
