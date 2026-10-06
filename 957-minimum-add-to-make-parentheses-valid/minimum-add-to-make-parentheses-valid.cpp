class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char& c: s){
            if(!st.empty()){
                char a = st.top();
                if(a == '(' && c == ')'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }
        return st.size();   
    }
};