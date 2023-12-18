class Solution {
public:
    int ans = 0;
    
    void printBoard(vector<vector<bool>> &board, int n){
        for(int i = 0; i < n; i++){
            for(int t = 0; t < n; t++){
                cout<< board[i][t]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    vector<vector<bool>> changeBoard(vector<vector<bool>> board, int x, int y, int &n){
        for(int i = 0; i < n; i++){
            board[x][i] = 0;
            board[i][y] = 0;
        }
        
        for(int b = 1; x+b < n && y+b < n; b++) board[x+b][y+b] = 0;
        for(int b = 1; x+b < n && y-b >= 0; b++) board[x+b][y-b] = 0;
        for(int a = 1; x-a >= 0 && y+a < n; a++) board[x-a][y+a] = 0;
        for(int a = 1; x-a >= 0 && y-a >= 0; a++) board[x-a][y+a] = 0;
        
        //cout<<"x : "<<x<< ", y : "<<y<<endl;
        //printBoard(board, n);
        return board;
    } 
    
    void countQueen(vector<vector<bool>> v, int x, int y, int n, int cnt){
        //cout<< "cnt : "<<cnt<<endl; 
        bool end = true;
        for(int i = x+1; i < n; i++){
            for(int t = 0; t < n; t++){
                if(v[i][t] == 1){
                    end = false;
                    countQueen(changeBoard(v,i,t,n), i, t, n, cnt+1);
                }
            }
        }
        if(end == true && cnt == n){
            ans++;
            return;
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, 1));
        
        for(int i = 0; i < n; i++){
            countQueen(changeBoard(board, 0,i, n), 0, i, n, 1);
        }
        
        return ans;
    }
};