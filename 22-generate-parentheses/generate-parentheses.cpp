class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> sa = {""};
        for(int i = 0; i < 2 * n;i++){
            int m = sa.size();
            for(int j = 0; j < m; j++){
                string s = sa[j];
                int open = 0;
                int closed = 0;
                for(auto& c: s){
                    if(c == '(')open++;
                    else closed++;
                }
                if(open > closed && open < n){
                    sa.push_back(s + ')');
                    sa.push_back(s + '(');
                }
                else if(open > closed && open == n){
                    sa.push_back(s + ')');
                }
                else{
                    sa.push_back(s + '(');
                }
            }
            erase_if(sa, [i](const std::string& s) {
                return s.size() == i;
            });
        }
        return sa;
    }
};