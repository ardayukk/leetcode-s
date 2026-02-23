class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        int n = s.size();
        for(int i = 0; i <= n - k; i++){
            us.insert(s.substr(i, k));
        }
        int m = pow(2,k);
        return us.size() == m;
    }
};