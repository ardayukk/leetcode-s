class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector<int> soln(n);
        int init = 0;
        int index = 0;
        int tot_g = 0;
        int tot_c = 0;
        for(int i = 0; i < n; i++){
            tot_g += gas[i];
            tot_c += cost[i];
        }
        if(tot_c > tot_g){
            return -1;
        }
        for(int i = 0; i < n; i++){
            init += gas[i] -cost[i];
            if(init <= 0){
                init = 0;
                index = i + 1;
            }
        }
        index = index % n;
        return index;
    }
};
//greedy approach: starting from s if it fails at any step t there is no optimal solution inbetween s and t because each of those will fail at most at t since the only difference be that they do not have additional boost from d[s]