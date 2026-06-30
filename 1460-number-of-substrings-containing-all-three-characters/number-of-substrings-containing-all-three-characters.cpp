class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> pra(n, -1);
        pra[0] = (s[0] == 'a') ? 0 : -1;
        for(int i = 1; i < n; i++) {
            if (s[i] == 'a') pra[i] = i;
            else pra[i] = pra[i - 1];
        }

        vector<int> prb(n, -1);
        prb[0] = (s[0] == 'b') ? 0 : -1;
        for(int i = 1; i < n; i++) {
            if (s[i] == 'b') prb[i] = i;
            else prb[i] = prb[i - 1];
        }

        vector<int> prc(n, -1);
        prc[0] = (s[0] == 'c') ? 0 : -1;
        for(int i = 1; i < n; i++) {
            if (s[i] == 'c') prc[i] = i;
            else prc[i] = prc[i - 1];
        }

        long long ans = 0;

        for(int i = n - 1; i >= 0; i--) {
            int j = min({pra[i], prb[i], prc[i]});
            if (j == -1) break;
            ans += j + 1;
        }
        return (int)ans;
    }
};