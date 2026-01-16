class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_map<int,bool> u;
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i; j < hFences.size(); j++){
                u[abs(hFences[i] - hFences[j])] = true;
            }
        }
        int max = 0;
        for(int i = 0; i <vFences.size(); i++){
            for(int j = i; j < vFences.size(); j++){
                int temp = abs(vFences[i] - vFences[j]);
                if(u[temp] && max < temp){
                    max = temp;
                }
            }
        }
        if(max == 0){
            return -1;
        }
        long long a = 1LL * max * max;
        a %= 1000000007;
        return (int)a;

    }
};