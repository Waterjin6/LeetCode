class Solution {
public:
    map<string, int> m;
    
    int numDecodings(string s) {
        if(m[s] > 0)return m[s];
        if(s.length() == 0)return 0;
        
        if(s[0] == '0')return 0;
        if(s.length() == 1)return 1;
        if(s.length() == 2){
            //cout<<s<<endl;
            if(s[1] == '0'){
                if(s[0] <= '2')return 1;
                else return 0;
            }
            if(s > "26")return 1;
            else return 2;
        }
        
        int ans = numDecodings(s.substr(1));
        
        
        if(s.substr(0,2) <= "26") ans += numDecodings(s.substr(2));
        
        m[s] = ans;
        
        return ans;
    }
};