class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sI = 0, tI = 0;
        if(s.length() == 0)return true;
        while(sI < s.length() && tI < t.length()){
            if(s[sI] == t[tI]){
                sI++;
                if(sI == s.length())return true;
            }
            tI++;
        }
        
        return false;
        
    }
};