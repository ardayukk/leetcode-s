class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for(int i : nums){
            int c = 0;
            while(i != 0){
                c++;
                result.push_back(i % 10);
                i /= 10;
            }
            reverse(result.end() - c, result.end());
        }

        return result;
    }
};