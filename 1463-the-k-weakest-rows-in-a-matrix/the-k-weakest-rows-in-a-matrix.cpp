class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        vector<pair<int,int>> v; // {count1s, index}
        
        for(int i = 0; i < n; i++){
            v.push_back({count1s(mat[i]), i});
        }

        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first == b.first)
                return a.second < b.second; // smaller index first
            return a.first < b.first;       // fewer 1s first
        });

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].second);
        }
        return res;
    }

    int count1s(vector<int>& vec){
        int l = 0, r = vec.size() - 1;
        int ans = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(vec[mid] == 1){
                ans = mid + 1; // count = last index + 1
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};