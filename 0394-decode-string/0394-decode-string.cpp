class Solution {
public:
    string decString(string s, int &i){
        string sub = "", n = "", dec;
        
        for(; i < s.length()&& s[i] != ']'; i++){
            if(!isdigit(s[i])) sub += s[i];
            else {
                while(isdigit(s[i])) n += s[i++];
                i++;
                dec = decString(s, i);
                for(int t = 0; t < stoi(n); t++) sub += dec;
                n = "";
                //i++;
            }
        }
        
        return sub;
    }
    
    string decodeString(string s) {
        int i = 0;
        string ans = decString(s, i);
        return ans;
    }
};