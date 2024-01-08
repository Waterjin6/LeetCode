class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd = false;
    TrieNode() {
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }          
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* t = root;
        
        for(int i = 0; i < word.length(); i++){
            if(t->child[word[i]-'a'] == NULL) t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* t = root;
        
        for(int i = 0; i < word.length(); i++){
            //cout<< word[i]<<endl;
            if(t->child[word[i]-'a'] == NULL)return false;
            t = t->child[word[i]-'a'];
        }
        
        if(t->isEnd == true)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t = root;
        
        for(int i = 0; i < prefix.length(); i++){
            if(t->child[prefix[i]-'a'] == NULL)return false;
            t = t->child[prefix[i]-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */