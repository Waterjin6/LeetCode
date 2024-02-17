class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> order(numCourses);
        vector<int> cnt(numCourses, 0);
        
        for(auto i : pre) {
            order[i[1]].push_back(i[0]);
            cnt[i[0]]++;
        }
        
        queue<int> q;
        int x;
        
        for(int i = 0; i < numCourses; i++){
            if(cnt[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        
        while(!q.empty()){
            x = q.front();
            q.pop();
            
            for(int i = 0; i < order[x].size(); i++){
                cnt[order[x][i]]--;
                if(cnt[order[x][i]] == 0) {
                    q.push(order[x][i]);
                    ans.push_back(order[x][i]);
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(cnt[i] != 0)return {};
        }
        return ans;
        
    }
};