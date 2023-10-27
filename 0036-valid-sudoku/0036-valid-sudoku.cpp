class Solution {
public:
    vector<vector<char>> board;
    
    bool check1(int x, int y, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(i == x)continue;
            if(board[x][y] == '.')continue;
            if(board[x][y] == board[i][y])return false;
        }
        return true;
    }
    
    
    bool check2(int x, int y, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(i == y)continue;
            if(board[x][y] == '.')continue;
            if(board[x][y] == board[x][i])return false;
        }
        return true;
    }
    
    
    bool check3(int x, int y, vector<vector<char>>& board){
        int startX = (x/3)*3, startY = (y/3)*3;
        
        for(int i = 0; i < 3; i++){
            for(int t = 0; t < 3; t++){
                if((startX+i == x)&&(startY+t == y))continue;
                if(board[x][y] == '.')continue;
                if(board[x][y] == board[startX+i][startY+t])return false;
            }
        }
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int t = 0; t < 9; t++){
                if(board[i][t] == '.')continue;
                //cout<< "x , y : "<< i<<", "<<t<<endl;
                
                // check condition 1
                if(check1(i,t, board) == false)return false;
                //cout<<"1";
                
                // check condition 2
                if(check2(i,t, board) == false)return false;
                //cout<<"2";
                
                // check condition 3
                if(check3(i,t, board) == false)return false;
                //cout<<"3";
                //cout<<endl;
            }
        }
        return true;
    }
};