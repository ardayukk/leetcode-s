class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxn = 1;
        for(int i = 0 ; i < n - 1; i++){
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++){
                freq[s[j]]++;
                int count = -1;
                bool doItake = true;
                for(auto& a: freq){
                    if(count == -1){
                        count = a.second;
                    }
                    else{
                        if(a.second != count){
                            doItake = false;
                            break;
                        }
                    }
                }
                if(doItake){
                    maxn = max(maxn, j - i + 1);
                }
            }
            
        }
        return maxn;
    }
};