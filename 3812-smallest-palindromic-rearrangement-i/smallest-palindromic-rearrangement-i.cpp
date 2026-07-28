class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(auto& c: s){
            mp[c]++;
        }
        
        string r = "";
        char od;
        bool odf = false;
        for(auto& [c, i] : mp){
            if(i % 2 == 1){
                od = c;
                odf = true;
            }
            for(int j = i / 2; j > 0; j--){
                r += c;
            }
        }
        string reversed = r;
        reverse(reversed.begin(), reversed.end());


        if(odf){
            r = r + od;
            r += reversed;
        }
        else{
            r += reversed;
        }
        return r;
    }
};