class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string news = "";
        int count = 0;

        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push('(');
                count++;
            }
            else if(s[i] == ')'){
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                    // cout << temp<< " ";
                }
                // reverse(temp.begin(), temp.end());
                count--;
                st.pop();
                for(auto& c: temp){
                    st.push(c);
                }
                temp = "";
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            news += st.top();
            st.pop();
        }
        reverse(news.begin(), news.end());
        return news;
    }
};