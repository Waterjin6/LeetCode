class Solution {
public:
    bool checkIsDigit(string &s, int st, int ed){
        if(st > ed)return false;
        
        for(int i = st; i <= ed; i++){
            if(isdigit(s[i])== false)return false;
        }
        return true;
    }
    
    bool isInteger(string &s, int st, int ed){
        if(st > ed)return false;
        
        if((s[st] == '+')||(s[st] == '-'))st++;
        if(st > ed)return false;
        
        return checkIsDigit(s, st, ed);
    }
    
    bool isDecimal(string &s, int st, int ed){
        if(st > ed)return false;
        
        if((s[st] == '+')||(s[st] == '-'))st++;
        if(st > ed)return false;
        
        vector<int> dotIdxs;
        for(int i = st; i <= ed; i++){
            if(s[i] == '.')dotIdxs.push_back(i);
        }
        
        if(dotIdxs.size() > 1)return false;
        if(dotIdxs.size() == 1){
            if(dotIdxs[0] == st) return checkIsDigit(s, st+1, ed);
            else if(dotIdxs[0] == ed)return checkIsDigit(s, st,ed-1);
            else return (checkIsDigit(s, st, dotIdxs[0]-1)&&checkIsDigit(s, dotIdxs[0]+1, ed));
        }
        return checkIsDigit(s, st, ed);

    }
    
    
    bool isNumber(string s) {
        vector<int> eIdxs;
        for(int i = 0; i < s.length(); i++){
            if((s[i] == 'E')||(s[i] == 'e'))eIdxs.push_back(i);
        }
        
        if(eIdxs.size() > 1)return false;
        
        if(eIdxs.size() == 1){
            return ((isDecimal(s, 0, eIdxs[0]-1))||isInteger(s, 0, eIdxs[0]-1))&&(isInteger(s, eIdxs[0]+1, s.length()-1));
        }
        
        return isDecimal(s, 0, s.length()-1)||isInteger(s, 0, s.length()-1); // case 0
    }
};