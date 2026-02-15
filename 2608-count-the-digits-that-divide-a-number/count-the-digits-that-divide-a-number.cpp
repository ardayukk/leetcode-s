class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        string s = to_string(num);

        for(auto c: s){
            int a = c - '0';
            if(num % a == 0){
                count++;
            }
        }
        return count;
    }
};