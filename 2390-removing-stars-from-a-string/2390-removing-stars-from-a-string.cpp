class Solution {
public:
    string removeStars(string s) {
        stack<char> stC;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*')stC.pop();
            else stC.push(s[i]);
        }
        string ans = "";
        
        while(!stC.empty()){
            ans += stC.top();
            stC.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};