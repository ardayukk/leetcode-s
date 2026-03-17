class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string snew;
        for (auto &c : s) {
            if (c != '-') {
                snew += toupper(c);
            }
        }

        string ans;
        int cnt = 0;

        for (int i = snew.size() - 1; i >= 0; i--) {
            ans += snew[i];
            cnt++;

            if (cnt == k && i != 0) {
                ans += '-';
                cnt = 0;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};