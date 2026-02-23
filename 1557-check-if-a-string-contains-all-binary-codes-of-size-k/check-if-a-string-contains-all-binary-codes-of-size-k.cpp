class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        int n = s.size();
        for(int i = 0; i <= n - k; i++){
            us.insert(s.substr(i, k));
        }
        int m = pow(2,k) - 1;
        for(int i = 0; i <= m; i++){
            if(us.find(toBinaryK(i,k)) == us.end()){
                return false;
            }
        }
        return true;
    }

    string toBinaryK(int n, int k) {
        string s;
        for (int i = k - 1; i >= 0; --i) {
            s.push_back(((n >> i) & 1) ? '1' : '0');
        }
        return s;
    }
};