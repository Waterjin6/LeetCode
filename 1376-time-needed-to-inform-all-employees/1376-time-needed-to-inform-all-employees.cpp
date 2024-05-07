class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> under(n);
        
        int ans = 0, xIdx,xSum;
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++) if(manager[i] > -1) under[manager[i]].push_back(i);
        
        q.push({headID, 0});
        
        while(!q.empty()){
            xIdx = q.front().first;
            xSum = q.front().second;
            
            q.pop();
                
            if(under[xIdx].size() == 0) ans = max(ans, xSum);
            for(int i = 0; i < under[xIdx].size(); i++)q.push({under[xIdx][i], xSum + informTime[xIdx]});
        }
        return ans;
    }
};