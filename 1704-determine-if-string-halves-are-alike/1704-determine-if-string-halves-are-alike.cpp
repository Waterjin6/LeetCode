class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        unordered_set<char> dict = {'A', 'a', 'E','e','I','i','O','o','U','u'};
        for(int i = 0; i < s.length()/2; i++){
            if(dict.count(s[i])) cnt1++;
        }
        
        for(int i = s.length()/2; i < s.length(); i++){
            if(dict.count(s[i])) cnt2++;
        }
        
        return cnt1 == cnt2;
    }
};