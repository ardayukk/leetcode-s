#include <queue>
class MyStack {
private:
    queue<int> queueIn, queueSwap;
public:
    MyStack() {
    }
    
    void push(int x) {
        queueIn.push(x);
    }
    
    int pop() {
        while(queueIn.size() > 1){
            queueSwap.push(queueIn.front());
            queueIn.pop();
        }
        int elt = queueIn.front();
        queueIn.pop();
        swap(queueIn, queueSwap);
        return elt;
    }
    
    int top() {
        while(queueIn.size() > 1){
            queueSwap.push(queueIn.front());
            queueIn.pop();
        }
        int elt = queueIn.front();           
        queueSwap.push(queueIn.front());
        queueIn.pop();
        swap(queueIn, queueSwap);
        return elt;
    }
    
    bool empty() {
        return queueIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */