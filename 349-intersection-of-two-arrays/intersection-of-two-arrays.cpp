class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for(int i: nums1){
            us.insert(i);
        }
        vector<int> intersect;
        unordered_set<int> us1;

        for(int i: nums2){
            if(us.find(i) != us.end()){
                us1.insert(i);
            }
        }
        return vector<int> (us1.begin(), us1.end());
        
    }
};