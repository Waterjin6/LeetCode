class Solution {
public:
    vector<string> ans;
    
    void makeString(int a, int b, string s){
        if((a == 0)&&(b== 0)) ans.push_back(s);
        
        if(a > 0) makeString(a-1, b, s + "(");
        
        if((b > 0)&&(a < b)) makeString(a, b-1, s+ ")");
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        makeString(n,n,"");
        return ans;
    }
};