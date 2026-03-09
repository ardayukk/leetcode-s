class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i] +nums[i - 1];
        }
        this -> vec = nums;
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return vec[right];
        return vec[right] - vec[left - 1];
    }
private:
    vector<int> vec;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */