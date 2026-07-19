class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> used(26, false);
        string result;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (used[c - 'a']) {
                continue;
            }

            while (!result.empty() &&
                   result.back() > c &&
                   last[result.back() - 'a'] > i) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            used[c - 'a'] = true;
        }

        return result;
    }
};