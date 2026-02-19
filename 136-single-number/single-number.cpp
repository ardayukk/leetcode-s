class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i : nums){
            if(freq[i] == 0){
                freq[i]++;
            }
            else{
                freq[i]--;
            }
        }
        for(auto& a: freq){
            if(a.second == 1) return a.first;
        }
        return 0;
    }
};