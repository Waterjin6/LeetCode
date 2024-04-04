class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, c = 0;
        for(char x : s){
            if(x == '(') c++;
            else if(x == ')') {
                ans = max(c, ans);
                c--;
            }
        }
        return ans;
    }
};