#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> land(n);
        for(int i = 0; i < n; i++){
            land[i] = {landStartTime[i], landDuration[i]};
        }

        vector<pair<int,int>> water(m);
        for(int i = 0; i < m; i++){
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> prefMinWaterDur(m);
        prefMinWaterDur[0] = water[0].second;
        for(int i = 1; i < m; i++){
            prefMinWaterDur[i] = min(prefMinWaterDur[i - 1], water[i].second);
        }

        vector<int> suffMinWaterEnd(m);
        suffMinWaterEnd[m - 1] = water[m - 1].first + water[m - 1].second;
        for(int i = m - 2; i >= 0; i--){
            suffMinWaterEnd[i] = min(suffMinWaterEnd[i + 1], water[i].first + water[i].second);
        }

        vector<int> prefMinLandDur(n);
        prefMinLandDur[0] = land[0].second;
        for(int i = 1; i < n; i++){
            prefMinLandDur[i] = min(prefMinLandDur[i - 1], land[i].second);
        }

        vector<int> suffMinLandEnd(n);
        suffMinLandEnd[n - 1] = land[n - 1].first + land[n - 1].second;
        for(int i = n - 2; i >= 0; i--){
            suffMinLandEnd[i] = min(suffMinLandEnd[i + 1], land[i].first + land[i].second);
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            int landEnd = land[i].first + land[i].second;
            int idx = lower_bound(water.begin(), water.end(), make_pair(landEnd, 0)) - water.begin();
            
            if(idx < m) {
                ans = min(ans, suffMinWaterEnd[idx]);
            }
            if(idx > 0) {
                ans = min(ans, landEnd + prefMinWaterDur[idx - 1]);
            }
        }

        for(int i = 0; i < m; i++){
            int waterEnd = water[i].first + water[i].second;
            int idx = lower_bound(land.begin(), land.end(), make_pair(waterEnd, 0)) - land.begin();
            
            if(idx < n) {
                ans = min(ans, suffMinLandEnd[idx]);
            }
            if(idx > 0) {
                ans = min(ans, waterEnd + prefMinLandDur[idx - 1]);
            }
        }

        return ans;
    }
};