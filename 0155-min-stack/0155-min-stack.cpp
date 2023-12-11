class MinStack {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<int> st;
    unordered_map<int, int> m;
    
    MinStack() {
        
    }
    
    void push(int val) {
        pq.push(val);
        st.push(val);
        m[val]++;
        return;
    }
    
    void pop() {
        m[st.top()]--;
        st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        //cout<< pq.top()<<endl;
        while(m[pq.top()] == 0)pq.pop();
        return pq.top();
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