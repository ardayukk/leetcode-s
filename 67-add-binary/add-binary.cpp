class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        if (b.size() >= a.size()) {
            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0) sum += a[i--] - '0';
                if (j >= 0) sum += b[j--] - '0';
                
                s.push_back((sum % 2) + '0');
                carry = sum / 2;
            }
        } 
        else {
            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0) sum += a[i--] - '0';
                if (j >= 0) sum += b[j--] - '0';
                
                s.push_back((sum % 2) + '0');
                carry = sum / 2;
            }
        }

        reverse(s.begin(), s.end());
        return s;
    }
};