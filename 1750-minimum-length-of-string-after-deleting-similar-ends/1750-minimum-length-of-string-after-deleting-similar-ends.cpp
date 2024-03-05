class Solution {
public:
    int minimumLength(string s) {
        int b = 0, e = s.length()-1;
        char c ='d';
        
        while(b < e && s[b] == s[e]){
            c = s[b];
            
            while(b<=e && s[b] == c) b++;
            while(b<=e && s[e] == c)e--;
        }
        return e-b+1;
    }
};