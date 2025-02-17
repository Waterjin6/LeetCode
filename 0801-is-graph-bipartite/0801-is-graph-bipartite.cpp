class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();

        vector<int> v;
        queue<int> q;
        vector<int> tag(sz, -1);

        int qv;

        q.push(0);
        tag[0] = 0;

        while(!q.empty()){
            qv = q.front();
            cout<< "qv : "<<qv<<endl;
            q.pop();
//            if(graph[qv].size() == 0) tag[qv] = 0;
            for(int i = 0; i < graph[qv].size(); i++){
                //if(graph[qv][i] < qv) continue;
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

 
//        if(!q.empty())return false;
        for(int i = 0; i < sz; i++){
            cout<< tag[i]<<" ";
        }cout<<endl;
        /*for(int i = 0; i < sz; i++){
            if(tag[i] == -1 && graph[i].size() > 0)return false;
        }*/
        /*for(int i = 0; i < sz; i++){
            if(tag[i] == -1&& graph[i].size() > 0)return false;
        }*/
        return true;
    }
};