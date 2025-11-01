class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int lthSmallestElement = n - k + 1;
        return findLthSmallest(nums, 0, n - 1, lthSmallestElement);
    }

    int mm(vector<int>& nums, int p, int r){
        int n = r - p + 1;
        if(n <= 5){
            BubbleSort(nums, p, r);
            // median index for subarray [p..r]
            return nums[p + (n - 1) / 2];
        }

        vector<int> medianArray;
        int groups = n / 5;
        int leftover = n % 5;

        for(int i = 0; i < groups; i++){
            int start = p + 5*i;
            int end = start + 4;
            BubbleSort(nums, start, end);
            medianArray.push_back(nums[start + 2]); // median of 5
        }

        if(leftover > 0){
            int start = p + 5 * groups;
            int end = r; // leftover group
            BubbleSort(nums, start, end);
            // median of leftover group
            medianArray.push_back(nums[(start + end) / 2]);
        }

        return mm(medianArray, 0 , (int)medianArray.size() - 1);
    }

    int findLthSmallest(vector<int>& nums, int p, int r, int k){
        int n = r - p + 1;
        if(n == 1) return nums[p];

        int pivot = mm(nums, p, r);

        // One new array, two pointers; count equals explicitly.
        vector<int> numsNew(n);
        int left = 0;         // next write for < pivot
        int right = n - 1;    // next write for > pivot (from end)
        int eq = 0;           // count of == pivot

        for(int i = p; i <= r; i++){
            if(nums[i] < pivot){
                numsNew[left++] = nums[i];
            }
            else if(nums[i] > pivot){
                numsNew[right--] = nums[i];
            }
            else{
                ++eq; // just count equals; no need to place them
            }
        }

        int leftCount = left;     // # of < pivot
        int equalCount = eq;      // # of == pivot
        int greaterStart = right + 1; // first index with > pivot in numsNew
        // right part size = n - greaterStart

        if(k <= leftCount){
            // recurse into strictly-less region [0 .. leftCount-1]
            return findLthSmallest(numsNew, 0, leftCount - 1, k);
        }
        else if(k <= leftCount + equalCount){
            // kth falls inside the equals band
            return pivot;
        }
        else{
            // recurse into strictly-greater region [greaterStart .. n-1]
            return findLthSmallest(
                numsNew,
                greaterStart,
                n - 1,
                k - leftCount - equalCount
            );
        }
    }

    void BubbleSort(vector<int>& A, int p, int r){
        for (int i = p; i < r; i++)
            for (int j = p; j < r -(i - p); j++)
                if (A[j] > A[j+1])
                    swap(A[j], A[j+1]);
    }
};
