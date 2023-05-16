class Solution {
public:
    bool isValid(string s) {
        stack<char> set;
        map<char,char> m;
        
        m.insert(make_pair(')','('));
        m.insert(make_pair(']','['));
        m.insert(make_pair('}','{'));
        
        for(int i = 0; i < s.length(); i++){
            if((s[i] == '(')||(s[i] == '[')||(s[i] == '{'))set.push(s[i]);
            else if((s[i] == ')')||(s[i] == '}')||(s[i] == ']')){
                if(set.size() <= 0)return false;
                else if(set.top() != m[s[i]])return false;
                else set.pop();
            }
            else return false;
        }
        if(set.size() > 0)return false;
        else return true;
    }
};