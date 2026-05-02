class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxn = k;
        unordered_map<char,int> freq;

        int l = 0;
        for(int i = 0; i < s.size(); i++){
            
            int maxInFreq = 0;
            char maxcharInFreq = 0;
            
            freq[s[i]]++;

            for(auto&[c,in] : freq){
                maxInFreq = max(maxInFreq, in);
                if(maxInFreq == in){
                    maxcharInFreq = c;
                }
            }

            int windowSize = i - l + 1;

            if(windowSize - maxInFreq <= k){
                maxn = max(windowSize, maxn);
            }
            else{
                freq[s[l]]--;
                l++;
            }
            

        }
        return maxn;
    }
};