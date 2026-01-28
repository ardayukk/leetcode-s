class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1){
            return true;
        }
        bool up = false;
        if(!isupper(word[0]) && isupper(word[1])){
            return false;
        }

        if(isupper(word[1])){
            up = true;
        }
        for(int i = 2; i < n; i++){
            if(up){
                if(!isupper(word[i])){
                    return false;
                }
            }
            else{
                if(isupper(word[i])){
                    return false;
                }
            }

        }
        return true;
    }
};