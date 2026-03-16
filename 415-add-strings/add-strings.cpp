class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2.size() > num1.size()) return addStrings(num2, num1);
        string newstr = "";
        int n = num1.size();
        int m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        for(int i = 0; i < n; i++){
            if(i >= m){
                int newint = (num1[i] - '0') + carry;
                if(newint > 9){
                    carry = 1;
                    newint -= 10;
                }
                else{
                    carry = 0;
                }
                newstr = newstr + char('0' + newint);
            }    
            else{
                int newint = (num1[i] - '0') + (num2[i] - '0') + carry;
                if(newint > 9){
                    carry = 1;
                    newint -= 10;
                    newstr = newstr + char('0' + newint);
                }
                else{
                    carry = 0;
                    newstr = newstr + char('0' + newint);
                }
            }
        }
        if(carry) newstr = newstr + '1';
        reverse(newstr.begin(), newstr.end());
        return newstr;
    }
};