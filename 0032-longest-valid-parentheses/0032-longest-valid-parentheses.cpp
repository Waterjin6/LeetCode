class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, bef;
        stack<int> st;
        
        for(int i = 0; i < s.length(); i++){ // 짝 맞는 것들 다 쳐내
            if(s[i] == '(') st.push(i);
            else {
                if(st.empty() || s[st.top()] == ')') st.push(i);
                else st.pop();
            }
        }
        
        if(st.empty())return s.length();
        st.push(s.length());
        
        bef = st.top();
        st.pop();
        
        while(!st.empty()){
            ans = max(ans, bef - st.top()-1);
            bef = st.top();
            st.pop();
        }
        ans = max(ans, bef);
        return ans;
    }
};