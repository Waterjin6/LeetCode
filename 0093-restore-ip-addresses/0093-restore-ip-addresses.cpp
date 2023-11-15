class Solution {
public:
    vector<string> ans;
    
    void makeAddress(int cnt, string s, string str){
        if(cnt == 4){
            if(s.length() != 0)return;
            ans.push_back(str);
            return;
        }
        if(s.length() == 0) return;
        if(cnt > 0)str +='.';
        //if(s == "541")cout<<" h : "<<str<<endl;
        for(int i = 1; i <= s.length() && i <= 3; i++){
           // if(s == "541")cout<<"BB : "<<s.substr(0,i)<<endl;
           if(s[0] == '0' && i > 1)return;
           if(s.substr(0,i).length() < 3 || s.substr(0,i) <= "255") {
               //cout<< str + s.substr(0,i)<<endl;
               makeAddress(cnt+1, s.substr(i), str + s.substr(0,i));
           }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        string str = "";
        if(s.length() < 4)return ans;
        
        makeAddress(0, s, str);
        return ans;
    }
};