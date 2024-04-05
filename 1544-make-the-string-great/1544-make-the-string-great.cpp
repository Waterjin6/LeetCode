class Solution {
public:
    string makeGood(string s) {
        if(s == "")return "";
       for(int i = 0; i < s.length()-1; i++){
           if(s[i] != s[i+1] && tolower(s[i]) == tolower(s[i+1])){
               s.erase(i,2);
               return makeGood(s);
           }
       }

        return s;
    }
};