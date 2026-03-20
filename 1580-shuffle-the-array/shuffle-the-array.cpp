class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> news(2* n);
        int j = 0;
        int k = n;
        for(int i = 0; i < 2 * n; i++){
            if(i % 2 == 0){
                news[i] = nums[j++];
            }
            else{
                news[i] = nums[k++];
            }
        }
        return news;
    }
};