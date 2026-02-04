class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = hoursNeeded(mid, piles);

            if (hours <= h) {
                ans = mid;          // mid works, try smaller
                right = mid - 1;
            } else {
                left = mid + 1;     // mid too slow
            }
        }
        return ans;
    }

    long long hoursNeeded(int k, vector<int>& piles) {
        long long total = 0;
        for (int p : piles) {
            total += (p + k - 1) / k;   
        }
        return total;
    }
};
