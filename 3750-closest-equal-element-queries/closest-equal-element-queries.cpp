class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = queries.size();
        int m = nums.size();

        vector<int> ans;

        unordered_map<int, vector<int>> um;

        for(int i = 0; i < nums.size(); i++){
            um[nums[i]].push_back(i);
        }

        for (auto& [key, vec] : um) {
            sort(vec.begin(), vec.end());
        }

        for(int i = 0; i < n; i++){
            int a = nums[queries[i]];

            vector<int>& vec = um[a];
            int vs = vec.size();

            if(vs == 1) {
                ans.push_back(-1);
                continue;
            }

            int l = 0;
            int r = vs - 1;
            int mid;
            while(l <= r){
                mid = l + (r - l) / 2;

                if(vec[mid] > queries[i]){
                    r = mid - 1;
                }
                else if(vec[mid] < queries[i]){
                    l = mid + 1;
                }
                else{
                    break;
                }
            }


            l = mid - 1;
            if(l == -1) l = vs - 1;

            r = mid + 1;
            if(r == vs) r = 0;


            int ldiff = abs(vec[l] - queries[i]);
            int rdiff = abs(vec[r] - queries[i]);

            ldiff = min(ldiff, m - ldiff);
            rdiff = min(rdiff, m - rdiff);

            if(ldiff > rdiff){
                ans.push_back(rdiff);
            }
            else{
                ans.push_back(ldiff);
            }
        }
        
        return ans;
    }
};