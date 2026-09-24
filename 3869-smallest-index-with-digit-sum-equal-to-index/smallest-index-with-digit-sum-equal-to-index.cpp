class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i == foo(nums[i])) return i;
        }
        return -1;
    }
    int foo(int a){
        int b = 0;
        while(a != 0){
            b += a % 10;
            a /= 10;
        }
        return b;
    }
};