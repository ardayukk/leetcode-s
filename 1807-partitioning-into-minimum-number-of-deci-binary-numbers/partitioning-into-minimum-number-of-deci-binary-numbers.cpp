class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(char c: n){
            m = max(m, c- '0');
        }
        return m;
    }
};