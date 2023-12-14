class Solution {
public:
    bool isValid(int x, int y, int xSz, int ySz){
        return (x >= 0 && y >= 0 && x < xSz && y < ySz);
    }
    
    int getAliveNeighborCnt(int x,int y, vector<vector<int>>& board){
        int cnt = 0;
        int dx[8] = {-1,1,0,0, -1, -1, 1, 1}; // up down left right up-left up-right down-left down-right
        int dy[8] = {0,0,-1,1, -1, 1, -1, 1};
        
        for(int i = 0; i < 8; i++){
            if(isValid(x+dx[i], y+dy[i], board.size(), board[0].size())== true && board[x+dx[i]][y+dy[i]] == 1)cnt++;
        }
        //cout << " x : "<< x<<", y : "<<y<<" cnt : "<<cnt<<endl;
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans = board;
        int c;
        
        for(int i = 0; i < board.size(); i++){
            for(int t = 0; t < board[0].size(); t++){
                c = getAliveNeighborCnt(i,t,board);
                //cout<< c <<" ";
                if(board[i][t] == 0 && c == 3)ans[i][t] = 1;
                else if(c < 2 || c > 3)ans[i][t] = 0; 
            }
            cout<<endl;
        }
        
        board = ans;
        return;
    }
};