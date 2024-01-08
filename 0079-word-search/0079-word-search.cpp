class Solution {
public:
    bool ans = false;
    int dx[4] = {-1, 1, 0, 0}; //
    int dy[4] = {0, 0, -1, 1};
    int xs, ys;
    
    bool inRange(int &x, int &y){
        return x >= 0 && x < xs && y >= 0 && y < ys;
    }
    
   void isPossible(vector<vector<char>> board, string &word, int idx, int x, int y){
        if(word.length() == idx){
            ans = true;
            return;
        }
        int nx, ny;
        for(int i = 0; i < 4; i++){
            nx = x+dx[i];
            ny = y+dy[i];
            if(inRange(nx, ny) && board[nx][ny] == word[idx]){
                board[nx][ny] = 0;
                isPossible(board, word, idx+1, nx, ny);
                board[nx][ny] = word[idx];
            }
        }
        return;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        xs = board.size();
        ys = board[0].size();
        int cnt = 0;
        bool isTh = false;
        
        while(cnt < word.length()){
            isTh = false;
            
            for(int i = 0; i < xs; i++){
                if(find(board[i].begin(), board[i].end(), word[cnt]) != board[i].end()){
                    isTh = true;
                    break;
                }
            }
            if(isTh == false)return false;
            cnt++;
        }

        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(board[i][t] == word[0]){
                    //cout<< i <<" "<<t<<endl;
                    board[i][t] = '0';
                    isPossible(board, word, 1, i, t);
                    if(ans == true)return true;
                    board[i][t] = word[0];
                }
            }
        }
            
        return ans;    
    }
};