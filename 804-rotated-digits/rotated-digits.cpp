class Solution {
public:
    bool isGood(int n){
        return (n == 2 || n == 5 || n == 6 || n == 9);
    }
    bool isUnrotateable(int n){
        return (n == 3 || n == 4 || n == 7);
    }
    int rotatedDigits(int n) {
        int c = 0;
        for(int i = 1; i <= n; i++){
            string s = to_string(i);
            bool b = false;
            for(int j = 0; j < s.size(); j++){
                char ch = s[j] - '0';

                if(isUnrotateable(ch)){
                    b = false;
                    break;
                }
                else{
                    if(isGood(ch)){
                        b = true;
                    }
                }
            }
            c += b;
        }
        return c;
    }
};