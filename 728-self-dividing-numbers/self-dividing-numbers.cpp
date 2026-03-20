class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
    bool isSelfDividing(int n){
        int ncpy = n;
        while(n != 0){
            if(n % 10 == 0) return false;
            if(ncpy % (n % 10) != 0) return false;
            n /= 10;
        }
        return true;
    }
};