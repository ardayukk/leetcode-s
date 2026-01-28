class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int s = duration;
        for(int i = 0; i < n - 1; i++){
            if(duration >= timeSeries[i + 1] - timeSeries[i]){
                s+= (timeSeries[i + 1] - timeSeries[i]);
            }
            else{
                
                s += duration;
            }
        }
        return s;
    }
};