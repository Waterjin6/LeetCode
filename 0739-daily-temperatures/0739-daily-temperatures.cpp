class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int ts = temperatures.size();
        vector<int> ans(ts, 0);
        st.push(ts-1);
        
        for(int i = ts-2; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])st.pop();
            if(!st.empty()) ans[i] = st.top()-i;
            st.push(i);
        }
        return ans;
    }
};