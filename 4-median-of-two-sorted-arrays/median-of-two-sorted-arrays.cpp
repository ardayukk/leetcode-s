class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = (int)nums1.size();
        int n = (int)nums2.size();

        int totalLeft = (m + n + 1) / 2;

        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = totalLeft - i;

            int Aleft  = (i == 0 ? INT_MIN : nums1[i - 1]);
            int Aright = (i == m ? INT_MAX : nums1[i]);
            int Bleft  = (j == 0 ? INT_MIN : nums2[j - 1]);
            int Bright = (j == n ? INT_MAX : nums2[j]);

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if (((m + n) & 1) == 1) {
                    return (double)max(Aleft, Bleft);
                } else {
                    int leftMax = max(Aleft, Bleft);
                    int rightMin = min(Aright, Bright);
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                // took too many from nums1
                hi = i - 1;
            } else {
                // took too few from nums1
                lo = i + 1;
            }
        }

        // should never reach here if inputs are valid
        return 0.0;
    }
};