class Solution {
public:
    bool detectCapitalUse(string word) {
        int sz = word.size();
        
        if(sz < 2)return true;
        
        if(word[0] >= 'A' && word[0] <= 'Z'){
            if(word[1] >= 'A' && word[1] <= 'Z'){
                for(int i = 2; i < sz; i++){
                    if(!(word[i] >= 'A' && word[i] <= 'Z'))return false;
                }
                return true;
            }
            else{
                for(int i = 2; i < sz; i++){
                    if((word[i] >= 'A' && word[i] <= 'Z'))return false;
                }
                return true;
            }
        }
        
        for(int i = 1; i < sz; i++){
            if((word[i] >= 'A' && word[i] <= 'Z'))return false;
        }
        return true;
        
    }
};