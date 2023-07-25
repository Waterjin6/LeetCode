class Solution {
public:
    
    string addBinary(string a, string b) {
        string ans ="", t;
        char u = 0;
        int size = a.size(), i = 0;
        
        if(a.size() < b.size()){ // a is bigger
            t = a;
            a = b;
            b = t;
        }
        
        // reverse a, b
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        for(; i < b.size(); i++){
            if(a[i] == b[i]){
                if(u == '1')ans+="1";
                else ans += "0";
                
                if(a[i] - '1' == 0)u = '1';
                else u = '0';
            }
            else { // a[i] + b[i] = 1
                if(u == '1'){
                    ans+="0";
                    u = '1';
                }
                else{
                    ans += "1";
                    u = '0';
                }
            }
        }
        
        for(;i < a.size();i++){
            if(a[i] == u){
                ans+="0";
                
                if(a[i] - '1' == 0)u = '1';
                else u = '0';
            }
            else { // a[i] + b[i] = 1
                ans +="1";
                u = '0';
            }
        }
        cout << ans;
        if(u == '1') ans +="1";
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};