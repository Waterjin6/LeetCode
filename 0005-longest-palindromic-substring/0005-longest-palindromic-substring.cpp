class Solution {
public:
    int sz;
    string s;

    bool possible(int st, int sz){
        for(int i = 0; i < sz/2; i++){
            if(s[st + i] != s[st+sz-1-i])return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int st = 0;
        sz = s.length();
        this->s = s;

        while(sz > 0){
            for(st = 0; (st < st+sz)&&(st+sz <= s.length()); st++){
                if(possible(st, sz)) return s.substr(st, sz);
            }
            sz--;
        }

        string ans = s.substr(st, sz);
        return ans;
    }
};