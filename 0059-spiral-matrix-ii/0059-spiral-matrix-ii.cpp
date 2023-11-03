class Solution {
public:
    int dx[4] = {0, 1, 0, -1}; //right, down, left, up
    int dy[4] = {1, 0, -1, 0};
    
    void change(int &x, int &y, int &d, int &n, vector<vector<int>> &board){
        if((x + dx[d] == -1)||(x + dx[d] == n)||(y + dy[d] == -1)||(y + dy[d] == n))d = (d+1)%4;
        if(board[x + dx[d]][y + dy[d]] != 0)d = (d+1)%4;
        
        x += dx[d];
        y += dy[d];
        return;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        
        int x = 0, y = 0, d = 0;
        
        for(int i = 1; i <= n*n; i++){
            board[x][y] = i;
            if(n != 1)change(x,y,d,n, board);
        }
        
        return board;
    }
};