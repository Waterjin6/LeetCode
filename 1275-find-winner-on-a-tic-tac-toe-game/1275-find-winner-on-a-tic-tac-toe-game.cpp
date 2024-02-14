class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int board[3][3] = {0};
        
        for(int i = 0; i < moves.size(); i++){
            if(i % 2 == 0)board[moves[i][0]][moves[i][1]] = 1;
            else board[moves[i][0]][moves[i][1]] = 2;
        }
        /*for(int i = 0; i < 3; i++){
            for(int t = 0; t < 3; t++)cout<< board[i][t]<<" ";
            cout<<endl;
        }*/
        for(int i = 0; i < 3; i++){
            if(board[i][0] == 0) continue;
            if(board[i][0]== board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 1)return "A";
                else return "B";
            }
        }
        
        for(int i = 0; i < 3; i++){
            if(board[0][i] == 0) continue;
            if(board[0][i]== board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 1)return "A";
                return "B";
            }
        }
        
        if(board[1][1] > 0){
            if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                if(board[0][0] == 1)return "A";
                return "B";
            }
            if(board[0][2] == board[1][1] && board[2][0] == board[1][1]){
                if(board[1][1] == 1)return "A";
                return "B";
            }
        }
        for(int i = 0; i < 3; i++){
            for(int t = 0; t < 3; t++){
                if(board[i][t] == 0)return "Pending";
            }
        }
        
        return "Draw";
    }
};