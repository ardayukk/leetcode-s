class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(bobSizes.begin(), bobSizes.end());
        int aliceSum = 0;
        for(int i: aliceSizes) aliceSum += i;
        int bobSum = 0;
        for(int i: bobSizes) bobSum += i;
        int n = aliceSizes.size();
        int diff = aliceSum - bobSum;
        for(int i = 0; i < n; i++){
            int curr = aliceSizes[i];
            int b = search(bobSizes,  curr -  diff/2);
            if(b != -1){
                return {curr, curr - diff / 2};
            }
            cout << curr - diff / 2 << endl;
        }
        return {0,0};
    }
    int search(vector<int>& nums, int target) {
        int p = 0;
        int r = nums.size() - 1;

        while (p <= r) {
            int mid = p + (r - p) / 2;

            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                p = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

};