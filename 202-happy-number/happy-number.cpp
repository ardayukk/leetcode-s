class Solution {
public:
    bool isHappy(int n) {
        int counter = 100;
        int k = n;
        for(int i = 0; i < counter; i++){
            int kcp = k;
            int nextk = 0;
            while(kcp != 0){
                nextk += pow(kcp % 10, 2);
                kcp /= 10;
            }
            if(nextk == 1) return true;
            k = nextk;
        }
        return false;
    }
};