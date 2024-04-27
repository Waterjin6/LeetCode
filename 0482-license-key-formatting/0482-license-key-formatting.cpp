class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "", s1 = "";
        int sl, fsz, idx = 0;
        
        for(char x : s){
            if(x == '-') continue;
            else s1 += (isdigit(x)) ? x : toupper(x);
        }
        
        sl = s1.length();
        if(sl == 0)return "";
        fsz = (sl % k == 0 ) ? k : sl % k;

        for(int i = 0; i < fsz; i++) ans += s1[idx+i];
        idx += fsz;
        
        while(idx < sl){
            ans += '-';
            for(int i = 0; i < k; i++) ans += s1[idx+i];
            idx += k;
        }
            
        return ans;
    }
};