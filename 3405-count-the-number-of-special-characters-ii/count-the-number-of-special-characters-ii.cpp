class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> us;
        int i = 0;
        int c = 0;
        int n = word.size();
        unordered_set<char> bam;
        unordered_set<char> bam2;
        for(int i = 0; i < n; i++){
            if(word[i] > 'Z'){
                if(us.find(word[i] - 32) != us.end() && us.find(word[i]) != us.end()){
                    if(bam.find(word[i]) == bam.end() && bam2.find(word[i]) != bam2.end()){
                        c--;
                        bam.insert(word[i]);
                    }
                }
                us.insert(word[i]);
            }
            else{
                if(us.find(word[i] + 32) != us.end() && us.find(word[i]) == us.end()){
                    bam2.insert(word[i] + 32);
                    c++;
                }
                us.insert(word[i]);
            }
        }
        return max(c,0);
    }
};