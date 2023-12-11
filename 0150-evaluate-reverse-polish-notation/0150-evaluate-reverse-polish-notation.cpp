class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i].length() > 1 || isdigit(tokens[i][0]))st.push(stoi(tokens[i]));
            else {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                if(tokens[i] =="*")st.push(a*b);
                else if(tokens[i] == "+")st.push(a+b);
                else if(tokens[i] == "-")st.push(a-b);
                else if(tokens[i] == "/")st.push(a/b);
            }
        }
        
        return st.top();
    }
};