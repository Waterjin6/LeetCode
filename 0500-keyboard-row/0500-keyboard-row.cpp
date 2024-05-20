class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> ans;
        int row;
        
        unordered_map<char, int>mp;
        for(int i = 0; i < 3; i++){
            for(char c : keyboard[i]) mp[c] = i;
        }
        
        for(string s : words){
            //cout<< "s : "<<s<<endl;
            row = mp[s[0]];
            //cout<< row<<endl;
            int i = 1;
            for(; i < s.length(); i++){
                if(mp[s[i]] != row) break;
            }
            //cout<<i<<endl;
            if(i == s.length()) ans.push_back(s);
        }
        
        return ans;
    }
};