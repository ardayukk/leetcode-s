class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        for(int i : nums){
            if(i < pivot){
                v1.push_back(i);
            }
            else if(i == pivot){
                v2.push_back(i);
            }
            else{
                v3.push_back(i);
            }
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        v1.insert(v1.end(), v3.begin(), v3.end());

        return v1;
    }
};