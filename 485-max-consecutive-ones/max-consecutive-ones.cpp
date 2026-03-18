class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctr = 0;
        int mx = 0;
        for(int i : nums){
            if(i == 1) ctr++;
            else ctr = 0;
            mx = max(mx, ctr);
        }
        return mx;
    }
};