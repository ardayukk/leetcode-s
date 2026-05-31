class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long masscopy = (long long) mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < n; i++){
            if(masscopy >= asteroids[i]){
                masscopy += asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};