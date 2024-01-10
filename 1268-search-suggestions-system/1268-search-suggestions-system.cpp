class TrieNode {
    public:
        TrieNode* child[26];
        vector<string> words;
        
        TrieNode(){
            for(int i = 0; i < 26; i++) child[i] = NULL;
            words.clear();
        }
};

class Solution {
public:
    void makeRoute(TrieNode* r, string &s){
        TrieNode* p = r;
        
        for(int i = 0; i < s.length(); i++){
            if(p->child[s[i]-'a'] == NULL) p->child[s[i]-'a'] = new TrieNode();
            p = p->child[s[i]-'a'];
            if(p->words.size() < 3)p->words.push_back(s);
        }

        return;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int ps = products.size();
        TrieNode* root = new TrieNode();
        
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        
        for(int i = 0; i < ps; i++){
            makeRoute(root,products[i]);
        }
        
        TrieNode* p = root;
        int i = 0;
        for(; p != NULL && i < searchWord.length(); i++){
            if(p->child[searchWord[i]-'a'] == NULL)break;
            else {
                p = p->child[searchWord[i]-'a'];
                ans.push_back(p->words);
            }
        }
        for(; i < searchWord.length(); i++)ans.push_back({});

        return ans;
    }
};