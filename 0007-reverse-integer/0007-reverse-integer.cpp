class Solution {
public:
    int reverse(int x) {

        string ans= "";
        if(x == -2147483648){
            ans.append("-");
            x = 2147483648;
        }
        else if(x < 0){
            ans.append("-");
            x *= -1;
        }
        
        string s = to_string(x);
        
        std::reverse(s.begin(),s.end());
        
        while(s[0] == '0'){
            s.erase(0,1);
        }
        if(s.size() == 0)return 0;
        if(s.length() > 10)return 0;
        if((s.length() == 10)&&(s > "2147483647"))return 0;
        
        ans += s;
        
        int ansInt = stoi(ans);
        return stoi(ans);
    }
};