class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n, -1);
        vector<bool> rVisited(n, 0);
        vector<bool> bVisited(n, 0);
        
        int d = 0, qs, xi, xc;
        
        vector<vector<int>> rEdges(n);
        vector<vector<int>> bEdges(n);
        
        for(int i = 0; i < redEdges.size(); i++) rEdges[redEdges[i][0]].push_back(redEdges[i][1]);
        for(int i = 0; i < blueEdges.size(); i++) bEdges[blueEdges[i][0]].push_back(blueEdges[i][1]);
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        q.push({0, 1});
        
        while(!q.empty()){
            qs = q.size();
            for(int i = 0; i < qs; i++){
                xi = q.front().first;
                xc = q.front().second;
                
                q.pop();
                if(xc == 0 && rVisited[xi] || xc == 1 && bVisited[xi])continue;
                if(dist[xi] == -1)dist[xi] = d;
                
                if(xc == 0){
                    rVisited[xi] = 1;
                    for(int r : rEdges[xi]) q.push({r, 1});
                }
                else{
                    bVisited[xi] = 1;
                    for(int b : bEdges[xi]) q.push({b, 0});
                }
            }
            d++;
        }
        
        return dist;
    }
};