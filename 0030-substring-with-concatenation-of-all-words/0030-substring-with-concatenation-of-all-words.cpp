class Solution {
public:
    bool check(string c, int wsz, string s, vector<string>& words, unordered_map<string, int> &m){
        //cout<< s<<endl;
        string sub;
        unordered_map<string, int> nm = m;
        nm[c]--;
    
        for(int i = 0; i <= s.length()-wsz; i += wsz){
            sub = s.substr(i, wsz);
            //cout<< "sub : "<<sub<<endl;
            if(nm[sub] == 0)return false;
            nm[sub]--;
        }
        
        for(auto i = nm.begin(); i != nm.end(); i++){
            if(i->second > 0)return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int wsz = words[0].length();
        unordered_map<string, int> m;
        vector<int> ans;
        string sub;
        
        if(s.length() < wsz*words.size())return ans;
        
        for(int i = 0; i < words.size(); i++){
            m[words[i]]++;
        }
        //cout<< "limit : "<< s.length()<<"-"<<wsz*words.size()<<endl;
        for(int i = 0; i <= s.length()-wsz*words.size();){
            //cout<< i<<endl;
            sub = s.substr(i, wsz);
            if(m[sub] == 0)i++;
            else {
                if(words.size() == 1)ans.push_back(i);
                else if(check(sub, wsz, s.substr(i+wsz, wsz*(words.size()-1)), words, m) == true){
                    ans.push_back(i);
                }
                //i += wsz;
                i++;
            }
        }
        
        return ans;
    }
};