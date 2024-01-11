class Solution {
public:
    void dfs(int &x, int &y, int &sz, vector<bool> &isVisited, vector<vector<int>>& isConnected){
        stack<int> visit;
        visit.push(y);
        int idx;
        while(!visit.empty()){
            idx = visit.top();
            visit.pop();
            isVisited[idx] = 1;
            
            for(int i = 0; i < sz; i++){
                if(isConnected[idx][i] == 1 && isVisited[i] == false){
                    visit.push(i);
                }
            }
       }
        //cout<< "hey"<<endl;
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cs = isConnected.size();
        vector<bool> isVisited(cs, 0);
        int grN = 0;
        
        for(int i = 0; i < cs; i++){
            if(isVisited[i] == true) continue;
            for(int t = 0; t < cs; t++){
                if(isConnected[i][t] == 1 && isVisited[t] == false){
                    isVisited[i] = 1;
                    dfs(i,t, cs, isVisited, isConnected);
                    grN++;
                }
            }
        }
        
        return grN;
    }
};