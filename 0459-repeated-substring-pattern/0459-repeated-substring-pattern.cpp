class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string word = "";
        
        int sl, start;

        sl = s.length();
        string sub = "";
        
        for(int size = sl/2; size > 0; size--){
            if(sl % size != 0)continue;
            sub = s.substr(0, size);
            for(start = size; start < sl; start += size){
                if(s.substr(start,size) != sub)break;
            }
            if(start == sl)return true;
        }
        return false;
    }
};