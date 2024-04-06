class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> l;
        int rc = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')l.push(i);
            else if(s[i]== ')'){
                if(l.size() == rc){
                    s.erase(i,1);
                    return minRemoveToMakeValid(s);
                }
                else rc++;
            }
        }
        if(l.size() > rc){
            s.erase(l.top(),1);
            return minRemoveToMakeValid(s);
        }
        return s;
    }
};