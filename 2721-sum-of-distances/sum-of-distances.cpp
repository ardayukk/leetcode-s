class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<pair<int, long long>>> um;

        for(int i = 0; i < nums.size(); i++){
            um[nums[i]].push_back(make_pair(i,0));
        }

        for(auto& [a,v]: um){
            v[0].second = v[0].first;
            for(int i = 1; i < v.size(); i++){
                v[i].second = v[i].first + v[i - 1].second;
            }
        }

        vector<long long> ans(nums.size());

        for(int i = 0; i < nums.size(); i++){
            vector<pair<int, long long>>& a = um[nums[i]];

            int l = 0;
            int r = a.size() - 1;
            int best = -1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                best = mid;
                if(a[mid].first > i){
                    r = mid - 1;
                }
                else if(a[mid].first < i){
                    l = mid + 1;
                }
                else{
                    break;
                }
            }

            long long temp = 0;

            long long leftSum = best == 0 ? 0 : a[best - 1].second;
            long long rightSum = a.back().second - a[best].second;

            long long leftCount = best;
            long long rightCount = a.size() - best - 1;

            temp += 1LL * i * leftCount - leftSum;
            temp += rightSum - 1LL * i * rightCount;

            ans[i] = temp;
        }
        
        return ans;
    }
};