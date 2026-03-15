class Solution {
public:
    priority_queue<string, vector<string>, greater<string>> pq;
    string getHappyString(int n, int k) {
        createString(n-1, "a");
        createString(n-1, "b");
        createString(n-1, "c");
        int pqs = pq.size();
        if(pqs < k){
            return "";
        }
        for(int i = 0; i < k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
    void createString(int n, string s){
        if(n == 0) {
            pq.push(s);
            return;
        }
        int a = s.size() - 1;
        if(s[a] == 'a'){
            createString(n-1, s + "b");
            createString(n-1, s + "c");
        }
        else if(s[a] == 'b'){
            createString(n-1, s + "a");
            createString(n-1, s + "c");
        }
        else{
            createString(n-1, s + "a");
            createString(n-1, s + "b");
        }
    }

};