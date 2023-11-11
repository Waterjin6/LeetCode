class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int pow = 1;
        
        while(columnNumber >= 1){
            if(columnNumber % 26 == 0){
                ans += 'Z';
                columnNumber -= 26;
            }
            else{
                ans += ('A' + columnNumber%26 -1);
            }
            columnNumber /= 26;

        }
        reverse(ans.begin(), ans.end());
        /*
        if(columnNumber >= 1){
            ans += ('A' + columnNumber - 1);
        }*/
        
        return ans;
    }
};