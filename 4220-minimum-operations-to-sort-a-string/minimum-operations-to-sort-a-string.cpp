class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }
        if(s.size() < 3){
            return -1;
        }
        char mn = s[0];
        char mx = s[0];

        for(int i = 0; i < n; i++){
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
        }
        if(mn == s[0]){
            return 1;
        }
        if(mx == s[n-1]){
            return 1;
        }

        for(int i = 1; i < n - 1; i++){
            if(s[i] == mn || s[i] == mx) return 2;
        }
        return 3;
    }
};