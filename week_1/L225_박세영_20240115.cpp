class MyStack {
    queue<int> i,o;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        int p;
        if(!i.empty()) {
            while(1) {
                p = i.front();
                i.pop();
                if(i.empty()) break;
                o.push(p);
            }
        }
        else if(i.empty()) {
            while(1) {
                p = o.front();
                o.pop();
                if(o.empty()) break;
                i.push(p);
            }
        }
        return p;

    }
    
    int top() {
        int t;
        if(!i.empty()) {
            while(1) {
                t = i.front();
                i.pop();
                o.push(t);
                if(i.empty()) break;
            }
        }
        else if(i.empty()) {
            while(1) {
                t = o.front();
                o.pop();
                i.push(t);
                if(o.empty()) break;
            }
        }
        return t;
    }
    
    bool empty() {
        if(i.empty()&&o.empty()) return true;
        return false;
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