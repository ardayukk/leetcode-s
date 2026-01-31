class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, pair<int,int>> um;
        int n = words1.size();
        for(int i = 0; i < n; i++){
            um[words1[i]].first++;
        }
        n = words2.size();
        for(int i = 0; i < n; i++){
            um[words2[i]].second++;
        }
        int g = 0;
        for(auto& b: um){
            if(b.second.second == 1 && b.second.first == 1) g++;
        }
        return g;
    }
};