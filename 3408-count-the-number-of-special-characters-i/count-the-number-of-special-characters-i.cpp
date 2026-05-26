class Solution {
public:
    int numberOfSpecialChars(string word) {
        sort(word.begin(), word.end(), [](auto& a , auto& b){
            return(a > b);
        });

        unordered_set<char> us;
        int i = 0;
        int c = 0;
        while(i < word.size() && word[i] > 'Z'){
            us.insert(word[i]);
            i++;
        }

        while(i < word.size()){
            if(us.find((word[i] + 32)) != us.end() && us.find(word[i]) == us.end()){
                us.insert(word[i]);
                c++;
            }
            i++;
        }
        return c;
    }
};