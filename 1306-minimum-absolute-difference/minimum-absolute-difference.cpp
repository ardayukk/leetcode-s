class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int absdiff = INT_MAX;
        vector<vector<int>> a;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            absdiff = min(absdiff, arr[i + 1] - arr[i]);
        }
        for(int i = 0; i < n - 1; i++){
            if(arr[i + 1] - arr[i] == absdiff){
                a.push_back({arr[i], arr[i + 1]});
            }
        }
        return a;
    }
};