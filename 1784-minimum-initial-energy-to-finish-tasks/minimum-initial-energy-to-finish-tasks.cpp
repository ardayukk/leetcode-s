class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>> diff;
        for(int i = 0; i < tasks.size(); i++){
            vector<int>& v = tasks[i];
            diff.push_back(make_pair(v[1] - v[0], i));
        }

        sort(diff.begin(), diff.end());

        vector<vector<int>> tasksNew = tasks;

        for(int i = 0; i < tasks.size();i++){
            tasksNew[i] = tasks[diff[tasks.size() - i - 1].second];
        }


        int l = 0;
        int r = 1000000000;
        int m;
        int bsf;
        while(l <= r){
            m = l + (r - l) / 2;
            bool a = doesSuffice(m, tasksNew);

            if(a){
                r = m - 1;
                bsf = m;
            }
            else{
                l = m + 1;
            }
        }

        return bsf;


    }

    bool doesSuffice(int m, vector<vector<int>>& tasks){
        for(int i = 0; i < tasks.size(); i++){
            if(m < tasks[i][1]) return false;
            m -= tasks[i][0];
        }
        return (m >= 0);
    }
};