class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            vec[i] = arr[i];
        }
        
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int pos = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

            ans[i] = pos + 1;
        }
        return ans;
    }
};