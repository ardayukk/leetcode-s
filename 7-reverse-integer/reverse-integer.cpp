class Solution {
using ll = long long;
public:
    int reverse(int x) {
        ll xll = 1LL * x;
        string s = "0";

        bool ispositive = (xll >= 0);

        xll = abs(xll);

        while(xll != 0){
            s.push_back('0' + (xll %10));
            xll/=10;
        }
        size_t pos = s.find_first_not_of('0');

        if (pos == string::npos)
            s = "0";
        else
            s.erase(0, pos);
        // cout << s;
        ll a = 0;
        for(auto&c : s){
            a*= 10;
            a += (c - '0');
        }
        if(a > INT_MAX || a < INT_MIN){
            return 0;
        }
        if(!ispositive) return (-1 * a);
        return a;
    }
};