class MinStack {
private: 
    stack <int> s,m;
public:
    MinStack() {
    }
    
    void push(int val) {
         if(m.empty()) m.push(val);
         else {
             if(m.top()>=val) {
                 m.push(val);
             }
         }
         s.push(val);
    }
    
    void pop() {
        if(s.top() == m.top()){
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        int min = m.top();
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */