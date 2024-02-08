class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> cnt(numCourses, 0);
        vector<vector<int>> bef(numCourses);
        queue<int> q;
        int x; 
        
        for(int i = 0; i < pre.size(); i++){
            cnt[pre[i][0]]++;
            bef[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(cnt[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            x = q.front();
            q.pop();
            
            for(int i = 0; i < bef[x].size(); i++){
                cnt[bef[x][i]]--;
                if(cnt[bef[x][i]] == 0) q.push(bef[x][i]);
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(cnt[i] > 0)return false;
        }
        
        return true;
    }
};