class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        
        while(columnNumber >= 1){
            if(columnNumber % 26 == 0){
                ans += 'Z';
                columnNumber -= 26;
            }
            else ans += ('A' + columnNumber%26 -1);
            
            columnNumber /= 26;

        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};