class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int sz = graph.size(), qs, f;

        vector<int> outCnt(sz, 0);
        vector<vector<int>> arrive_start(sz);
        queue<int> q;
        
        for(int i = 0; i < sz; i++){
            //cout<< "idx : "<< i<<endl;
            //if(i == 5)cout<< "5 size : "<< graph[i].size()<<endl;
            if(graph[i].size() == 0){
                //cout<< "i : "<< i <<endl;
                q.push(i);
                ans.push_back(i);
                continue;
            }
            for(int t = 0; t < graph[i].size(); t++){
                outCnt[i]++;
                arrive_start[graph[i][t]].push_back(i);
            }
        }
        cout<< ans.size()<<endl;
        while(!q.empty()){
            qs = q.size();
            for(int i = 0; i < qs; i++){
                f = q.front();
                q.pop();
                for(int t = 0; t < arrive_start[f].size(); t++){
                    //outCnt[arrive_start[f][t]]--;
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