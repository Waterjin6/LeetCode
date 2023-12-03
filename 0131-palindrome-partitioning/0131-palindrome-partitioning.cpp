class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPali(string s){
        if(s.length() <= 1)return true;
        
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-1-i])return false;
        }
        return true;
    }
    
    void makeStr(vector<string> v, string s){
        if(s == ""){
            ans.push_back(v);
            return;
        }
        
        for(int i = 1; i <= s.length(); i++){
            if(isPali(s.substr(0,i))){
                v.push_back(s.substr(0,i));
                makeStr(v, s.substr(i));
                v.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> strV;
        
        for(int i = 1; i <= s.length(); i++){
            if(isPali(s.substr(0,i))){
                strV.push_back(s.substr(0,i));
                makeStr(strV, s.substr(i));
                strV.pop_back();
            }
        }
        
        return ans;
    }
};