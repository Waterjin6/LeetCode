class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx = 0;
    
    StockSpanner() {
        st.push({-1, INT_MAX});
    }
    
    int next(int price) {
        while(st.top().second <= price)st.pop();
        int x = idx - st.top().first;
        st.push({idx++, price});
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */