class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3){
            return false;
        }
        int odd_count = 0;
        for(int i = 0; i < 3; i++){
            if(arr[i] % 2 == 1){
                odd_count++;
            }
        }
        if(odd_count == 3){
            return true;
        }
        for(int i = 3; i < n; i++){
            if(arr[i] % 2 == 1){
                odd_count++;
            }
            if(arr[i -3] % 2 == 1){
                odd_count--;
            }
            if(odd_count == 3){
                return true;
            }
        }
        return false;

        
    }
};