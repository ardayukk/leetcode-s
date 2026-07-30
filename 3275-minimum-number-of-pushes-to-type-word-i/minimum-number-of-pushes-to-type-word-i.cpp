class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(auto& c: word){
            v[(c- 'a')]++;
        }
        sort(v.begin(), v.end());

        int i = 0;
        while(v[i]== 0) i++;
        int j = 0;
        int k = 1;
        int s = 0;
        for(; i < 26; i++){
            s += (k * v[i]);
            j++;
            if(j == 8){
                j = 0;
                k++;
            }
        }
        return s;
    }
};