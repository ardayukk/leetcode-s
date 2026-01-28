class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int maxn = 0;
        int curr = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            total += (s[i] - '0');
            if(s[i] == '1'){
                curr++;
            }else{
                maxn = max(maxn, curr);
                curr = 0;
            }
        }

        maxn = max(maxn,curr);
        return maxn == total;
    }
};