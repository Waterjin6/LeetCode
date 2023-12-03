class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        // insert side O
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O')q.push({0,i});
            if(board[board.size()-1][i] == 'O')q.push({board.size()-1, i});
        }
        
        for(int i = 1; i < board.size()-1; i++){
            if(board[i][0] == 'O')q.push({i,0});
            if(board[i][board[0].size()-1] == 'O')q.push({i, board[0].size()-1});
        }

        vector<vector<char>> v(board.size(), vector<char>(board[0].size(), 'X'));
        //cout<<"hey"<<endl;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            v[p.first][p.second] = 'O';
            
            if(p.first+1 < board.size() && board[p.first+1][p.second] == 'O' && v[p.first+1][p.second] == 'X')q.push({p.first+1,p.second});
            if(p.first-1 >= 0 && board[p.first-1][p.second] == 'O'&& v[p.first-1][p.second] == 'X')q.push({p.first-1,p.second});
            if(p.second+1 < board[0].size() && board[p.first][p.second+1] == 'O'&& v[p.first][p.second+1] == 'X')q.push({p.first,p.second+1});
            if(p.second-1 >= 0 && board[p.first][p.second-1] == 'O'&& v[p.first][p.second-1] == 'X')q.push({p.first,p.second-1});
        }
        
        board = v;
        return;
    }
};