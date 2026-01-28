class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s;
        int a = 0;
        for(char c: jewels){
            s.insert(c);
        }
        for(char c: stones){
            if(s.find(c) != s.end()){
                a++;
            }
        }
        return a;
    }
};