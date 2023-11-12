class MyStack {
public:
    queue<int> in;
    queue<int> out;
    
    MyStack() {
        //queue<int> in = this->in;
        //queue<int> out = this->out;
    }
    
    void push(int x) {
        while(!in.empty()){
            out.push(in.front());
            in.pop();
        }
        
        in.push(x);
        
        while(!out.empty()){
            in.push(out.front());
            out.pop();
        }
        return;
    }
    
    int pop() {
        int x = top();
        in.pop();
        return x;
    }
    
    int top() {
        return in.front();
    }
    
    bool empty() {
        return in.empty();
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