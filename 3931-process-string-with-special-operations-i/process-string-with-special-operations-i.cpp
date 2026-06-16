class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto& c: s){
            if(c == '*'){
                if(res != ""){
                    res = res.substr(0, res.size() - 1);
                }
            }
            else if(c == '#'){
                res += res;
            }
            else if(c == '%'){
                reverse(res.begin(), res.end());
            }
            else{
                res += c;
            }
            
        }
        return res;
    }
};