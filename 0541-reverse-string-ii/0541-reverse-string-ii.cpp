class Solution {
public:
    string reverseStr(string s, int k) {
        int sz = s.length(), idx = 0;

        while(idx + 2*k <= sz){
            reverse(s.begin()+idx, s.begin()+idx+k);
            idx += 2*k;
        }

        if(idx + k <= sz) reverse(s.begin()+idx, s.begin()+idx+k);
        else reverse(s.begin()+idx, s.end());

        return s;
    }
};