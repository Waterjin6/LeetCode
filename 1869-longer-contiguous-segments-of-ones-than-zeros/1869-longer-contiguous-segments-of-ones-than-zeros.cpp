class Solution {
public:
    bool checkZeroOnes(string s) {
        char b;
        int l[2] = {0};
        int c[2] = {0};
        
        b = s[0];
        
        c[b-'0']++;
        
        for(int i = 1; i < s.length(); i++){
            if(s[i] == b) c[b-'0']++;
            else{
                l[b-'0'] = max(l[b-'0'], c[b-'0']);
                c[b-'0'] = 0;
                b = s[i];
                c[b-'0']++;
            }
        }
        
        return max(c[1],l[1]) > max(c[0],l[0]);
    }
};