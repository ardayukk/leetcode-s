class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this -> n = n;

        this -> nodes = vector<int>(n * 2);
        
        for(int i = 0; i < n; i++){
            nodes[i + n] = nums[i];
        }
        for(int i = n - 1; i >= 1; i--){
            nodes[i] = nodes[2 * i] +  nodes[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        
        int diff = val - nodes[index + n];
        int track = index + n;
        while(track != 0){
            nodes[track] += diff;
            track /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int ans = 0;
        while(left <= right){
            if(left % 2 == 1)
                ans += nodes[left++];

            if(right % 2 == 0)
                ans += nodes[right--];

            left /= 2;
            right /= 2;
        }
        return ans;
    }
private:
    int n;
    vector<int> nodes;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */