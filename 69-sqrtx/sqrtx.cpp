class Solution {
public:
int mySqrt(int x){
        long long a = x;
        for(long long i = 0; i < a + 6; i++){
            if(i* i > x){
                return i - 1;
            }
        }
        return x;
    }
};