class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(char c: moves){
            if(c == 'L'){
                y--;
                continue;
            }
            if(c == 'R'){
                y++;
                continue;
            }
            if(c == 'U'){
                x--;
                continue;
            }
            if(c == 'D'){
                x++;
                continue;
            }
        }
        return ((x * y) == 0 && (x + y) == 0);
        
    }
};