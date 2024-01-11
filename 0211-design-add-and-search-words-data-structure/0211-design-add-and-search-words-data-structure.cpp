class WordDictionary {
public:
    unordered_map<int, set<string>> dic;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        dic[word.length()].insert(word);
        return;
    }
    
    bool search(string word) {
        if(find(word.begin(),word.end(), '.') == word.end()){
            return dic[word.length()].count(word);
        }
        int ws = word.length();
        string w;
        for(auto it = dic[ws].begin(); it != dic[ws].end(); it++){
            int i = 0;
            for(i = 0; i < ws; i++){
                if(word[i] != '.' && (*it)[i] != word[i])break;
            }
            if(i == ws)return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */