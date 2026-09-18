class Solution {
public:
    bool isSubstringPresent(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i = 0; i < s.size() - 1; i++){
            string search = s.substr(i, 2);

            if (rev.contains(search)) {
                return true;
            }
        }
        return false;
    }
};