class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int a = 0;
        for(auto& i: arr1){
            bool f = true;
            for(auto& i2: arr2){
                if(abs(i - i2) <= d){
                    f = false;
                    break;
                }
            }
            if(f){
                a++;
            }
            f = false;
        }
        return a;   
    }
};