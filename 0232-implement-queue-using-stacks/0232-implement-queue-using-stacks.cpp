class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
        return;
    }
    
    int pop() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int x = out.top();
        out.pop();
        
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
        return x;
    }
    
    int peek() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int x = out.top();
        
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
        return x;
    }
    
    bool empty() {
        return in.empty();
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