class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> us;
        for(auto& c: magazine) us[c]++;
        for(auto& c: ransomNote){
            if(us[c] == 0){
                return false;
            }
            else{
                us[c]--;
            }
        }
        return true;
        
    }
};