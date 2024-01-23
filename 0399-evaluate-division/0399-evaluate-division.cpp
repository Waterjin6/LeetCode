class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> list;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++){
            //cout<< equations[i][0] <<"->"<<equations[i][1]<<", "<< values[i]<<endl;
            //cout<< equations[i][1] <<"->"<<equations[i][0]<<", "<< 1/values[i]<<endl;
        
            list[equations[i][0]].push_back({equations[i][1], values[i]});
            list[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        vector<double> ans(queries.size(), -1.0);
        
        for(int i = 0; i < queries.size(); i++){
            unordered_map<string, bool> isVisited;
            if(list[queries[i][0]].size() == 0)continue;
            queue<pair<string, double>> q;
            isVisited[queries[i][0]] = true;
            q.push({queries[i][0],1});
            string nd;
            double val;
            
            while(!q.empty()){
                tie(nd,val) = q.front();
                q.pop();
                //cout<< "nd : "<<nd <<" , val : "<<val<<endl;
                if(nd == queries[i][1]){
                    ans[i] = val;
                    break;
                }
                
                for(int i = 0; i < list[nd].size(); i++){
                    if(isVisited[list[nd][i].first])continue;
                    isVisited[list[nd][i].first] = true;
                    q.push({list[nd][i].first, val*list[nd][i].second});
                }
            }
            //cout<<endl<<endl;
        }
        return ans;        
    }
};