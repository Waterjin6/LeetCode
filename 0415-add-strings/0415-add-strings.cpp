class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int u = 0, i1 = num1.length()-1, i2 = num2.length()-1, x;
        
        while(i1 >= 0 || i2 >= 0 || u == 1){
            x = 0;
            if(i1 >= 0) x += (num1[i1--]-'0');
            if(i2 >= 0) x += (num2[i2--]-'0');
            x+= u;
            u = x/10;
            ans += to_string(x%10);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};