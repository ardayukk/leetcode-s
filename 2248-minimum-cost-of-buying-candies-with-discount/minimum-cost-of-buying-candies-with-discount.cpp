class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int j = n % 3;
        int c = 0;
        for(int i = 0; i < j; i++){
            c+= cost[i];
        }
        for(int i = j; i < n; i+= 3){
            c += cost[i + 2];
            c += cost[i + 1];
        }
        return c;

    }
};