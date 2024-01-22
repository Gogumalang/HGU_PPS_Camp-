class MyQueue {
private:
    stack<int> i,o; // i : input - push, o : output - pop
public:
    MyQueue() {
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        if(o.empty()) {
            while(!i.empty()) {
                o.push(i.top());
                i.pop();
            }
        }
        int p = o.top();
        o.pop();
        return p;
    }
    
    int peek() {
        if(o.empty()) {
            while(!i.empty()) {
                o.push(i.top());
                i.pop();
            }
        }
        int p = o.top();
        return p;
    }
    
    bool empty() {
        if(i.empty()&&o.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 