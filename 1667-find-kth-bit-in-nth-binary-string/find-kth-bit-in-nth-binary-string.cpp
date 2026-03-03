class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2; i <= n; i++){
            string c = reverseStr(s);
            s += "1";
            s += c;
        }
        return s[k - 1];
    }
    string reverseStr(string& s){
        string newstring = "";
        for(auto& c: s){
            if(c == '1'){
                newstring += "0";
            }
            else{
                newstring += "1";
            }
        }
        int n = newstring.size();
        for(int i = 0; i < n / 2; i++){
            swap(newstring[i], newstring[n - i - 1]);
        }
        return newstring;
    }
};