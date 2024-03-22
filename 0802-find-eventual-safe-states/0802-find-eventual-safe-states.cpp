class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int sz = graph.size(), qs, f;

        vector<int> outCnt(sz, 0);
        vector<vector<int>> arrive_start(sz);
        queue<int> q;
        
        for(int i = 0; i < sz; i++){
            outCnt[i] = graph[i].size();
            if(outCnt[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
            else{
                for(int t = 0; t < outCnt[i]; t++){
                    arrive_start[graph[i][t]].push_back(i);
                }
            }
        }

        while(!q.empty()){
            qs = q.size();
            for(int i = 0; i < qs; i++){
                f = q.front();
                q.pop();
                for(int t = 0; t < arrive_start[f].size(); t++){
                    if(--outCnt[arrive_start[f][t]] == 0){
                        q.push(arrive_start[f][t]);
                        ans.push_back(arrive_start[f][t]);
                    }
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};