class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = m - 1;
            int best = i - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;
                    l = mid + 1;  
                } else {
                    r = mid - 1;
                }
            }

            ans = max(ans, best - i);
        }

        return ans;
    }
};