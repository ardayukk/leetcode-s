class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> strs;
        int n = nums.size();
        for(auto& s: nums){
            strs.insert(s);
        }
        string s = "";
        for(int i = 0; i < n; i++){
            s += '0';
        }
        while(1){
            if(strs.find(s) == strs.end()){
                return s;
            }
            getBinaryNext(s, n);
        }
    return s;


    }
    void getBinaryNext(string& str, int& n){
        for(int i = n - 1; i >= 0; i--){
            if(str[i] == '0'){
                str[i] = '1';
                for(int j = i + 1; j < n; j++){
                    str[j] = '0';
                }
                break;
            }
        }
    }

};