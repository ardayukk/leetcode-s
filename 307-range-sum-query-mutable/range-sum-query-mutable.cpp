class NumArray {
private:
    int n;
    vector<long> tree;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(n * 4, 0);

        for(int i = 0; i < n; i++){
            tree[n + i] = nums[i];
        }
        for(int i = n - 1; i > 0; i--){
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
    }
    
    void update(int index, int val) {
        int prev = tree[n + index];
        tree[n + index] = val;
        int ind = n+index;
        ind >>= 1;
        while(ind > 0){
            tree[ind] += (val - prev);
            ind >>= 1;
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += n;
        right += n + 1;

        while (left < right) {
            if (left & 1)
                sum += tree[left++];

            if (right & 1)
                sum += tree[--right];

            left /= 2;
            right /= 2;
        }
        return sum;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */