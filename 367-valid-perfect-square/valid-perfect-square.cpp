class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0;
        long long r = num;

        while(l <= r){
            long long m = l + (r - l) /2;

            if(m * m - num == 0){
                return true;
            }
            else if(m * m - num > 0){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return false;
    }
};