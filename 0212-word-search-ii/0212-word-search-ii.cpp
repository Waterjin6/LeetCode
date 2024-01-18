class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd = false;

    TrieNode() {
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
};

class Solution {
public:
    vector<string> ans;
    int dx[4] = {-1, 1, 0, 0}; // u d l r
    int dy[4] = {0,0,-1,1};

    void check(int x,int y, vector<vector<char>>& board, string s, TrieNode* root){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == ' ') return;
        
        if(root->child[board[x][y]-'a'] != NULL){
            s += board[x][y];
            root = root->child[board[x][y]-'a'];
            if(root->isEnd == true){
                ans.push_back(s);
                root->isEnd = false;
            }
            char c = board[x][y];
            board[x][y] = ' ';
            for(int i = 0; i < 4; i++){
                check(x + dx[i],y + dy[i], board, s, root);
            }
            board[x][y] = c;
        }

        return;
    }

    void makeTrie(TrieNode* root, string& word){
        TrieNode* t = root;

        for(int i = 0; i < word.length(); i++){
            if(t->child[word[i]-'a'] == NULL) t->child[word[i]-'a'] = new TrieNode();
            t = t->child[word[i]-'a'];
        }
        t->isEnd = true;

        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); i++){
            makeTrie(root, words[i]);
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int t = 0; t < board[0].size(); t++){
                if(ans.size() == words.size())return ans;
                check(i,t, board, "", root);
            }
        }
        
        return ans;
    }
};