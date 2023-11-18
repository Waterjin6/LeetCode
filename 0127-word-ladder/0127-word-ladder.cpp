class Solution {
public:
    bool isAdja(string a, string b){
        int cnt = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i])cnt++;
        }
        if(cnt+1 == a.length())return true;
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wIdx = -1;
        
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord){
                wIdx = i;
                break;
            }
        }
        if(wIdx == -1) return 0;
        
        queue<pair<string,int>> adja;
        
        adja.push({wordList[wIdx],1});
        wordList.erase(wordList.begin()+wIdx);
        
        while(!adja.empty()){
            pair<string,int> s = adja.front();
            adja.pop();
            
            // check s and startword is adjacent
            if(isAdja(s.first, beginWord) == true)return s.second+1;
            
            for(int i = 0; i < wordList.size();){
                if(isAdja(s.first, wordList[i])){
                    adja.push({wordList[i], s.second+1});
                    wordList.erase(wordList.begin()+i);
                }
                else i++;
            }
        }
        
        return 0;
    }
};