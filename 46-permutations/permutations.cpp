#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> a;
            a.push_back(nums[i]);
            vector<int> b = nums;
            b.erase(b.begin() + i);
            permutes(a, b, result);
        }
        return result;
    }
    
    void permutes(vector<int> a, vector<int> b, vector<vector<int>>& result) {
        if (b.empty()) {
            result.push_back(a);
            return;
        }
        for (int i = 0; i < b.size(); ++i) {
            vector<int> newA = a;
            newA.push_back(b[i]);
            vector<int> newB = b;
            newB.erase(newB.begin() + i);
            permutes(newA, newB, result);
        }
    }
};