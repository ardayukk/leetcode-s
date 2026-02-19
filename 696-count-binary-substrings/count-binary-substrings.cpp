class Solution {
public:
    int countBinarySubstrings(string s) {
        int c0 = 0;
        int c1 = 0;
        int prevlen = 0;
        int total = 0;
        for(auto& c: s){
            if(c == '0'){
                if(c1 == 0){
                    c0++;
                }
                else{
                    total += min(prevlen, c1);
                    prevlen = c1;
                    c1 = 0;
                    c0++;
                }
            }
            else{
                if(c0 == 0){
                    c1++;
                }
                else{
                    total += min(prevlen,c0);
                    prevlen = c0;
                    c0 = 0;
                    c1++;
                }
            }
        }
        total += min(prevlen, c0 + c1);
        return total;
        

    }
};