class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> v;
        for(auto& i: nums1) freq[i]++;
        for(auto& i: nums2){
            if(freq[i] != 0){
                v.push_back(i);
                freq[i] --;
            }
        }
        return v;
    }
};