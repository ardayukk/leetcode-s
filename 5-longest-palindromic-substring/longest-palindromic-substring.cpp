class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n);

        int center = 0;
        int right = 0;

        int bestCenter = 0;
        int bestLength = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;

            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > bestLength) {
                bestLength = p[i];
                bestCenter = i;
            }
        }

        int start = (bestCenter - bestLength) / 2;

        return s.substr(start, bestLength);
    }
};