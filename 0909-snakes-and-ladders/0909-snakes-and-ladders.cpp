class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int> m;
        int idx = 1, xs = board.size(), ys = board[0].size(), turn = 0, qsz, ed = xs*ys;
        
        for(int i = xs-1; i >= 0; i--){
            for(int t= 0; t < ys; t++)m[idx++] = board[i][t];
            if(--i == -1)break;
            for(int t= ys-1; t >= 0; t--)m[idx++] = board[i][t];
        }
        
        /*for(int i = 1; i<= ed; i++){
            cout<< i <<" : "<< m[i]<< endl;
        }*/
        queue<int> q;
        q.push(1);
        
        int n, bd;
        
        while(!q.empty()){
            qsz = q.size();
            for(int i = 0; i < qsz; i++){
                n = q.front();
                //cout<< n<<endl;
                q.pop();
                if(n == ed)return turn;
                bd = min(ed, n+6);
                //cout<<"bd : "<<bd<<endl;
                for(int t = bd; t >= n+1; t--){
                    if(m[t] > 0){
                        //cout<<"hey"<<endl;
                        q.push(m[t]);
                        m[t] = 0;
                    }else if(m[t] == -1){
                        q.push(t);
                        m[t] = 0;
                    }
                }
            }
            turn++;
        }
        return -1;
        
    }
};