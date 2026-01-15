class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxhConsecutive = 1;
        int currConsecutive = 1;
        int prev = hBars[0];
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == prev + 1){
                currConsecutive++;
                prev = hBars[i];
            }
            else{
                maxhConsecutive = max(currConsecutive, maxhConsecutive);
                currConsecutive = 1;
                prev = hBars[i];
            }
        }
        maxhConsecutive = max(currConsecutive, maxhConsecutive);

        int maxvConsecutive = 1;
        currConsecutive = 1;
        prev = vBars[0];
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == prev + 1){
                currConsecutive++;
                prev = vBars[i];
            }
            else{
                maxvConsecutive = max(currConsecutive, maxvConsecutive);
                currConsecutive = 1;
                prev = vBars[i];
            }
        }

        maxvConsecutive = max(currConsecutive, maxvConsecutive);
        
        cout<< maxvConsecutive << " " << maxhConsecutive << endl;
        currConsecutive = min(maxvConsecutive, maxhConsecutive) + 1;
        return currConsecutive * currConsecutive;
        
    }
};