class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> s;
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            if(s.empty()){
                s.push({temperatures[i],i});
            }
            else{
                int curr = s.top().first;
                while(!s.empty() && s.top().first < temperatures[i]){
                    int j = s.top().second;
                    ans[j] = i - j;
                    s.pop();
                }
                s.push({temperatures[i], i});
            }
        }
        while(!s.empty()){
            int topi = s.top().second;
            s.pop();
            ans[topi] = 0;
        }
        return ans;
    }

};