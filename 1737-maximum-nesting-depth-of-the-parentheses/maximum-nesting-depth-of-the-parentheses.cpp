class Solution {
public:
    int maxDepth(string s) {
        int cn = 0;
        int maxn = 0;
        for(auto& c: s){
            if(c== '(') cn++;
            if(c == ')') cn--;
            maxn = max(maxn, cn);
        }
        return maxn;
    }
};