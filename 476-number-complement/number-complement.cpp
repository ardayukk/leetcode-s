class Solution {
public:
    int findComplement(int num) {
        long long a = 0;
        long long pos = 1;
        while(num != 0){
            int bit = 1 - (num % 2);
            num /= 2;
            
            a += (pos* bit);
            pos*= 2;
        }
        return int(a);
    }
};