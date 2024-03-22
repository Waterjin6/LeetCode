class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> outCnt(n, 0);
        vector<vector<int>> arrive_start(n);
        
        for(int i = 0; i < edges.size(); i++){
            outCnt[edges[i][0]]++;
             arrive_start[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i< n; i++){
            if(outCnt[i] == 0)q.push(i);
        }
        vector<int> ans;
        int x;
        while(!q.empty()){
            x = q.front();
            q.pop();
            if(arrive_start[x].empty())ans.push_back(x);
            for(int i = 0; i < arrive_start[x].size(); i++){
                if(--outCnt[arrive_start[x][i]] == 0)q.push(arrive_start[x][i]);
            }
        }
        
        return ans;
        
    }
};