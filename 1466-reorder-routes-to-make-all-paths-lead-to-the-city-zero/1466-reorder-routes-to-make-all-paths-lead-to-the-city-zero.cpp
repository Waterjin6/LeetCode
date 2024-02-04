class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> m;
        int ans = 0;
        
        for(int i = 0; i < connections.size(); i++){
            m[connections[i][0]].push_back(-connections[i][1]);
            m[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> isVisited(n, false);
        isVisited[0] = true;
        queue<int> q;
        q.push(0);
        int x;
        
        while(!q.empty()){
            x = q.front();
            q.pop();
            
            for(int i = 0; i < m[x].size(); i++){
                if(m[x][i] >= 0){
                    if(isVisited[m[x][i]] == false){
                        isVisited[m[x][i]] = true;
                        q.push(m[x][i]);
                    }
                }
                else{
                    if(isVisited[-m[x][i]] == false){
                        isVisited[-m[x][i]] = true;
                        ans++;
                        q.push(-m[x][i]);
                    }
                }
            }
        }
        return ans;
    }
};