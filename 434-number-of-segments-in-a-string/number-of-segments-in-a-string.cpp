class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)return 0;
        int a = 0;
        char prev = s[0];
        if(prev != ' ')a++;
        for(int i = 0; i < s.size(); i++){
            if(prev == ' ' && s[i] != ' ')a++;
            prev = s[i];
        }
        return a;
    }
};