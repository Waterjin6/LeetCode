class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length())return false;
        int idx = -1, cnt = 0;

        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                if(idx == -1) idx = i;
                else if(!(s1[idx] == s2[i] && s2[idx] == s1[i]))return false;
                cnt++;
            }
        }
        if(cnt == 0 || cnt == 2)return true;
        return false;
    }
};