class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ns = "";

        for (int i = 0; i < target.size(); i++) {
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
                ns += target[i];
                continue;
            }

            for (char c = target[i] + 1; c <= 'z'; c++) {
                if (freq[c - 'a'] > 0) {
                    freq[c - 'a']--;
                    ns += c;

                    for (char x = 'a'; x <= 'z'; x++)
                        ns += string(freq[x - 'a'], x);

                    return ns;
                }
            }

            for (int j = i - 1; j >= 0; j--) {
                freq[ns[j] - 'a']++;

                for (char c = target[j] + 1; c <= 'z'; c++) {
                    if (freq[c - 'a'] > 0) {
                        freq[c - 'a']--;

                        string ans = ns.substr(0, j);
                        ans += c;

                        for (char x = 'a'; x <= 'z'; x++)
                            ans += string(freq[x - 'a'], x);

                        return ans;
                    }
                }
            }

            return "";
        }

        if (next_permutation(ns.begin(), ns.end()))
            return ns;

        return "";
    }
};