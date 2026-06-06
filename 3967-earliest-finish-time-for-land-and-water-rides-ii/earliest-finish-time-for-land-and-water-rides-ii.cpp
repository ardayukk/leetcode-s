#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int lmin = INT_MAX;
        int wmin = INT_MAX;
        int l = INT_MAX;
        int w = INT_MAX;
        for(int i = 0; i < n; i++){
            l = min(l, landDuration[i] + landStartTime[i]);
        }
        for(int i = 0; i < m; i++){
            w = min(w, waterDuration[i] + waterStartTime[i]);
        }

        for(int i = 0; i < m; i++){
            lmin = min(lmin, max(waterStartTime[i], l) + waterDuration[i]);
            
        }

        for(int i = 0; i < n; i++){
            wmin = min(wmin, max(landStartTime[i] , w) + landDuration[i]);
        }

        return min(wmin, lmin);
    }
};