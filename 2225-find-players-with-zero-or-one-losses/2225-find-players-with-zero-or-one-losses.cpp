class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        
        for(int i = 0; i < matches.size(); i++){
            m[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        
        for(int i = 0; i < matches.size(); i++){
            if(m.find(matches[i][0]) == m.end())m.insert({matches[i][0], 0});
        }
        
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second == 0)ans[0].push_back(i->first);
            else if(i->second == 1)ans[1].push_back(i->first);
        }
        
        return ans;
    }
};