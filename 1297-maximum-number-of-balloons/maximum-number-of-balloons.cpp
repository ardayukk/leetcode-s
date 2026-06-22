class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int l = 0;
        int a = 0;
        int b = 0;
        int o = 0;
        int n = 0;

        for(auto& c: text){
            if(c == 'l'){
                l++;
            }
            if(c == 'a'){
                a++;
            }
            if(c == 'b'){
                b++;
            }
            if(c == 'o'){
                o++;
            }
            if(c == 'n'){
                n++;
            }

        }

        int ans = min({l/2, a, b, o/2, n});
        return ans;
    }
};