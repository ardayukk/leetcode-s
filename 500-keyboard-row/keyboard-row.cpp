class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1s = "qwertyuiop";
        string s2s = "asdfghjkl";
        string s3s = "zxcvbnm";

        unordered_set<char> r1, r2, r3;
        vector<unordered_set<char>> rs = {r1, r2, r3};

        for (char c : s1s) rs[0].insert(c);
        for (char c : s2s) rs[1].insert(c);
        for (char c : s3s) rs[2].insert(c);

        vector<string> v;

        for (int i = 0; i < words.size(); i++) {
            int which = -1;
            char first = tolower(words[i][0]);

            if (rs[0].find(first) != rs[0].end()) which = 0;
            else if (rs[1].find(first) != rs[1].end()) which = 1;
            else if (rs[2].find(first) != rs[2].end()) which = 2;

            if (which == -1) continue;

            bool flag = true;
            for (int j = 0; j < words[i].size(); j++) {
                char c = tolower(words[i][j]);
                if (rs[which].find(c) == rs[which].end()) {
                    flag = false;
                    break;
                }
            }

            if (flag) v.push_back(words[i]);
        }

        return v;
    }
};