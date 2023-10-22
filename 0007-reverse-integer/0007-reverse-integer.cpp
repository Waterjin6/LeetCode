class Solution {
public:
    int reverse(int x) {

        string ans= "";
        
        if(x == -1*pow(2,31)) return 0;
        
        if(x < 0){
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
        if((s.length() == 10)&&(s > to_string(pow(2,31)-1)))return 0;
        
        ans += s;
        
        int ansInt = stoi(ans);
        return stoi(ans);
    }
};