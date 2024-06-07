class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dic;
        string st, p, ans = "";
        bool flag = false;
        
        for(string s : dictionary) dic.insert(s);
        
        stringstream ss(sentence);
        
        while(ss >> st){
            p = "";
            flag = false;
            
            for(char x : st){
                p += x;
                if(dic.count(p)){
                    ans += p + ' ';
                    flag = true;
                    break;
                }
            }
            
            if(flag == false) ans += p + ' ';
        }
        ans.erase(ans.length()-1);
        return ans;
    }
};