class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0}, ans = 0;
        
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i] -'a']++;
            cnt[t[i] -'a']--;
        }
        for(int i = 0; i < 26; i++){
            ans +=  abs(cnt[i]);
        }
        return ans/2;
    }
};