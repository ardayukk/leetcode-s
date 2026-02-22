class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while( n != 0){
            if( n& 1){
                s += "1";
            }
            else{
                s+= "0";
            }
            n >>= 1;
        }
        int prev1 = -1;
        int currmax = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(prev1 == -1){
                    prev1 = i;
                }
                else{
                    currmax = max(currmax, i - prev1);
                    prev1 = i;
                }
            }
        }
        return currmax;

    }
};