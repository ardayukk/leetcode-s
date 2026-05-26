class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> flag(n, false);
        queue<pair<int,int>> q;
        q.push({0, 0}); // index, result
        flag[0] = true;

        unordered_map<int,vector<int>> um;
        for(int i = 0; i < arr.size(); i++){
            um[arr[i]].push_back(i);
        }

        while(!q.empty()){
            pair<int,int> p = q.front();

            
            if(p.first == n - 1){
                return p.second;
            }

            vector<int>& v = um[arr[p.first]];

            for(int& i: v){
                if(!flag[i]){
                    flag[i] = true;
                    q.push({i, p.second + 1});
                }
            }

            v.clear();

            if(p.first != 0 && !flag[p.first - 1]){
                q.push({p.first - 1, p.second + 1});
                flag[p.first - 1] = true;
            }

            if(p.first != n - 1 && !flag[p.first + 1]){
                q.push({p.first + 1, p.second + 1});
                flag[p.first + 1] = true;
            }

            q.pop();
        }

        return -1;
    }
};