class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101,0);

        for(auto& v: logs){
            years[v[0] - 1950]++;
            years[v[1] - 1950]--;
        }

        int ansn = years[0];
        int ansy = 0;
        for(int i = 1; i < 101; i++){
            years[i] = years[i] + years[i - 1];

            if(years[i] > ansn){
                ansn = years[i];
                ansy = i;
            }
        }

        return ansy + 1950;
    }
};