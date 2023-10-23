class Solution {
public:
    
    void removeWhitespace(string &s){
        while(isblank(s[0]) == true)s.erase(0,1);
        
        return;
    }
    
    
    void makeStringDigit(string &s){
        int b = 0, e = 0;
        
        for(; b < s.size(); b++){
            if(s[b] != '0')break;
        }
        
        for(; e < s.size(); e++){
            if(isdigit(s[e]) == false)break;
        }
        
        if(b >= e) s= '0';
        else s = s.substr(b, e);
        
        return;
    }
    
    
    int myAtoi(string s) {
        removeWhitespace(s); //step 1
        
        bool isNegative = false;
        
        if(s[0] == '-'){ // step 2
            isNegative = true;
            s.erase(0,1);
        }
        else if(s[0] == '+') s.erase(0,1);
        
        makeStringDigit(s); // step 3
        
        if(s.length() == 0)return 0;
        
        int limit =  -pow(2,31);
        if(isNegative == false)limit++;
        
        string limits = to_string(limit);
        limits.erase(0,1);
        
        //cout<<limits<<endl;
        
        // step 5
        if(s.length() > limits.length()) s = limits;
        else if((s.length() == limits.length())&&(s > limits)) s = limits;
        
        if(isNegative == true) s = '-' + s;
        
        int ans = stoi(s);
        
        return ans;
    }
};