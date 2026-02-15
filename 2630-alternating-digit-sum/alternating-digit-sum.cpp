class Solution {
public:
    int alternateDigitSum(int n) {
        int tot = 0;
        string s = to_string(n);
        bool doIadd = true;
        for(auto& c : s){
            if(doIadd)
                tot += (c - '0');
            else
                tot -= (c - '0');

            doIadd = !doIadd;
        }
        return tot;
    }
};