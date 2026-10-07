class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int i, int open,int leftRem, int rightRem, string cur){
        if(i == s.size()){
            if(open == 0 && leftRem == 0 && rightRem == 0){
                ans.push_back(cur);
            }
            return;
        }

        char c = s[i];
        if(c == '('){
            if(leftRem > 0){
                dfs(s, i + 1, open, leftRem - 1, rightRem, cur);
            }
            dfs(s, i + 1, open + 1, leftRem, rightRem, cur + '(');
        }
        else if(c == ')'){
            if(rightRem > 0){
                dfs(s, i+1, open, leftRem, rightRem - 1, cur);
            }
            if(open > 0){
                dfs(s, i + 1, open - 1, leftRem, rightRem, cur + ')');
            }
        }
        else{
            dfs(s, i + 1, open, leftRem, rightRem, cur + c);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0;
        int rightRem = 0;

        //calculate minimum removals
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        dfs(s, 0, 0, leftRem, rightRem, "");

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }

};