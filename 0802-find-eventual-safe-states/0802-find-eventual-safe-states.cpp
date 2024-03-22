class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int sz = graph.size(), f;

        vector<int> outCnt(sz, 0);
        vector<bool> safe(sz, 0);
        vector<vector<int>> arrive_start(sz);
        queue<int> q;
        
        for(int i = 0; i < sz; i++){
            for(int t = 0; t < graph[i].size(); t++) arrive_start[graph[i][t]].push_back(i);
            outCnt[i] = graph[i].size();
            if(outCnt[i] == 0) q.push(i);
        }
        //cout<< q.size()<<endl;

        while(!q.empty()){
            f = q.front();
            q.pop();
            safe[f] = 1;
            for(int t = 0; t < arrive_start[f].size(); t++){
                if(--outCnt[arrive_start[f][t]] == 0) q.push(arrive_start[f][t]);
            }
        }
        
        for(int i = 0; i < sz; i++){
            if(safe[i] == 1)ans.push_back(i);
        }
        
        return ans;
    }
};