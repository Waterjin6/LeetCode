class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        queue<char> w1;
        queue<char> w2;
    
        string ans = "";
        
        for(int i = 0; i < word1.length(); i++)w1.push(word1[i]);
        for(int i = 0; i < word2.length(); i++)w2.push(word2[i]);
        
        while(!w1.empty()&&!w2.empty()){
            ans += w1.front();
            w1.pop();
            ans += w2.front();
            w2.pop();
        }
        
        while(!w1.empty()){
            ans += w1.front();
            w1.pop();
        }
        while(!w2.empty()){
            ans += w2.front();
            w2.pop();
        }
              
        
        return ans;
    }
};