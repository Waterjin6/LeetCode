class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length();){
            if((!isalpha(s[i]))&&(!isdigit(s[i])))s.erase(i,1);
            else if((isdigit(s[i]))||(islower(s[i]))) i++;
            else if(isupper(s[i])){
                s[i] = tolower(s[i]);
                i++;
            }
        }
        
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-1-i])return false;
        }
        return true;
        
    }
};