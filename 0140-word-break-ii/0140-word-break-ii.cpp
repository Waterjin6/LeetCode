class Solution {
public:
    unordered_map<char, vector<string>> m;
    vector<string> ans;
    
    void findAnswer(string s, string add){
        if(s == ""){
            add.erase(add.end()-1);
            ans.push_back(add);
            return;
        }
        
        for(int i = 0; i < m[s[0]].size() /*&& s <= m[s[0]][i]*/; i++){
            //cout<<s.substr(0,m[s[0]][i].length())<<endl;
            if(s.substr(0,m[s[0]][i].length()) == m[s[0]][i]){
                findAnswer(s.substr(m[s[0]][i].length(), s.length()-m[s[0]][i].length()), add + m[s[0]][i] +" ");
            }
        }
        
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        
        for(int i = 0; i < wordDict.size(); i++){
            string wd = wordDict[i];
            m[wd[0]].push_back(wd);
        }
        
        string str = "";
        findAnswer(s, str);
        
        return ans;
    }
};