class Solution {
public:
    string makeLargestSpecial(string s) {
        
        vector<string> parts;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            balance += (s[i] == '1') ? 1 : -1;

            // When balance hits 0, s[start..i] is a primitive special substring
            if (balance == 0) {
                // Strip outer "1 ... 0" and recursively maximize the inside
                string inner = s.substr(start + 1, i - start - 1);
                string bestInner = makeLargestSpecial(inner);

                parts.push_back("1" + bestInner + "0");
                start = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string res;
        for (auto &p : parts) res += p;
        return res;
    }
};
