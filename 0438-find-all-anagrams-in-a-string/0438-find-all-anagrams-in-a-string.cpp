class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ps = p.length(), i = 0, ss = s.length();
        vector<int> hashS(26, 0);
        vector<int> hashP(26, 0);
        vector<int> ans;
        
        if(ss < ps)return ans;
        
        for(; i < ps; i++){
            hashS[s[i]-'a']++;
            hashP[p[i]-'a']++;
        }
        
        while(i < ss){
            if(hashS == hashP) ans.push_back(i-ps);
            
            hashS[s[i-ps]-'a']--;
            hashS[s[i]-'a']++;
            
            i++;
        }
        
        if(hashS == hashP) ans.push_back(i-ps);
        return ans;
    }
};