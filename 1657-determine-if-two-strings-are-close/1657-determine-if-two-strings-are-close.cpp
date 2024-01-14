class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        vector<int> v1;
        vector<int> v2;
        int ws = word1.length();
        
        if(ws != word2.length())return false;
        
        for(int i = 0; i < ws; i++) m1[word1[i]]++;
    
        for(int i = 0; i < ws; i++){
            if(m1[word2[i]] == 0) return false;
            m2[word2[i]]++;
        }
        
        for(auto i = m1.begin(); i != m1.end(); i++) v1.push_back(i->second);
        for(auto i = m2.begin(); i != m2.end(); i++) v2.push_back(i->second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
    }
};