class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        bool a = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++)m[s[i]]++;
        
        for(auto i = m.begin(); i != m.end(); i++){
            ans += (i->second)/2;
            i->second %= 2;
            a += i->second;
        }
        ans *= 2;
        if(a == true)ans++;
        
        return ans;
    }
};