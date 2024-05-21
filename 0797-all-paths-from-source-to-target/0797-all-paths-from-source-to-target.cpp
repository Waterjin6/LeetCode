class Solution {
public:
    vector<vector<int>> ans;
    
    void makeGraph(int idx, vector<int> v, vector<vector<int>>& graph){
        if(idx == graph.size()-1){
            ans.push_back(v);
            return;
        }
        if(graph[idx].size() == 0) return;
        
        for(int x : graph[idx]){
            v.push_back(x);
            makeGraph(x, v, graph);
            v.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v = {0};
        makeGraph(0, v, graph);
        return ans;    
    }
};