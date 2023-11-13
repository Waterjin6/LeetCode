class Solution {
public:
    bool isAnagram(string s, string t) {
        int cs[26] ={0}, ct[26] = {0};
        int n = s.length(); 
        if(t.length() != n)return false;
        
        for(int i = 0; i < n; i++){
            cs[s[i]-'a']++;
            ct[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(cs[i] != ct[i])return false;
        }
        
        return true;
    }
};