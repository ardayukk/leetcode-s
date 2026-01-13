class Solution {
public:
    vector<int> diff(const string& s) {
        vector<int> d;
        for (int i = 0; i + 1 < s.size(); i++) {
            d.push_back((s[i + 1] - 'a') - (s[i] - 'a'));
        }
        return d;
    }

    string oddString(vector<string>& words) {
        vector<int> d0 = diff(words[0]);
        vector<int> d1 = diff(words[1]);
        vector<int> d2 = diff(words[2]);

        vector<int> common;
        if (d0 == d1 || d0 == d2) {
            common = d0;
        } else {
            common = d1;
        }

        for (auto& w : words) {
            if (diff(w) != common) {
                return w;
            }
        }
        return "";
    }
};
