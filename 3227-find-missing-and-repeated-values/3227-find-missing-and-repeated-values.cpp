class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sz = grid.size();
        vector<int> ans;
        unordered_map<int, int>cnt;

        for(int i = 0; i < sz; i++){
            for(int t = 0; t < sz; t++){
                cnt[grid[i][t]]++;
                if(cnt[grid[i][t]]==2)ans.push_back(grid[i][t]);
            }
        }

        for(int i = 1; i <= sz*sz; i++){
            if(cnt[i] == 0)ans.push_back(i);
        }

        return ans;

    }
};