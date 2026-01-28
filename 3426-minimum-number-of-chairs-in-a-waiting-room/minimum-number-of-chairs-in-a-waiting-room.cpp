class Solution {
public:
    int minimumChairs(string s) {
        int n = s.size();
        int numb = 0;
        int maxn = 0; 
        for(int i = 0; i < n; i++){
            if(s[i] == 'E'){
                numb++;
            }
            else{
                maxn = max(maxn, numb);
                numb--;
            }
        }
        maxn = max(maxn, numb);
        return maxn;
    }
};