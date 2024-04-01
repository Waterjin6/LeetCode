class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool>(n,0));
        int ans = 0;
        for(int i = 0; i < roads.size(); i++){
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
            isConnected[roads[i][0]][roads[i][1]] = 1;
            isConnected[roads[i][1]][roads[i][0]] = 1;
        }
        
        for(int i = 0; i < n-1; i++){
            for(int t = i+1; t < n; t++){
                ans = max(ans, cnt[i]+cnt[t]-isConnected[i][t]);
            }
        }
        return ans;
    }
};