class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {

        while(s.size() != 1){
            s2.push(s.top());
            s.pop();
        }
        int x = s.top();
        s.pop();
        while(s2.size() != 0){
            s.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int peek() {
        while(s.size() != 1){
            s2.push(s.top());
            s.pop();
        }
        int x = s.top();
        s2.push(s.top());
        s.pop();
        while(s2.size() != 0){
            s.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        return s.size() == 0;
    }
private:
    stack<int> s;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */