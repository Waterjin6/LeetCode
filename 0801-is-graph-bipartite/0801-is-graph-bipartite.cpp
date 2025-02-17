class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();

        queue<int> q;
        vector<int> tag(sz, -1);

        int qv;

        q.push(0);
        tag[0] = 0;

        while(!q.empty()){
            qv = q.front();
            q.pop();

            for(int i = 0; i < graph[qv].size(); i++){
                if(tag[graph[qv][i]] == -1){
                    tag[graph[qv][i]] = (tag[qv] == 0) ? 1 : 0;
                    q.push(graph[qv][i]);
                }
                else if(tag[graph[qv][i]] == tag[qv]) return false;
            }

            if(q.empty()){
                for(int i = 0; i < sz; i++){
                    if(tag[i] == -1){
                        q.push(i);
                        tag[i] = 0;
                        break;
                    }
                }
            }
        }

 
        return true;
    }
};