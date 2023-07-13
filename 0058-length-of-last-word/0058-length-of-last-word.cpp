class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        string buffer;
        string n;
        int end, start;
        
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' '){
                end = i;
                break;
            }
        }
        
        for(int i = end; i >= 0; i--){
            if(s[i] == ' '){
                start = i;
                break;
            }
        }
        
        return end-start;
    }
};