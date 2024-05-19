class Solution {
public:

    void updateMap(int &z, int &o,int &m, int &n, vector<vector<int>> &map){
        queue<tuple<int,int,int>> q;
        int x, y, v;
        
        q.push({z,o, 1});
        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++){
                if(map[i][t] > 0 && z+i <= m && o+t <= n) q.push({z+i, o+t, map[i][t]+1});
            }
        }
        
        while(!q.empty()){
            tie(x,y,v) = q.front();
            q.pop();
            
            map[x][y] = max(map[x][y], v);
        }

        return;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size(), z = 0, o = 0, ans = 0;
        vector<vector<int>> map(m+1, vector<int>(n+1, 0)); 
        
        for(int i = 0; i < sz; i++){ // 수 맞추기
            z = 0;
            o = 0;
            for(char x : strs[i]){
                if(x == '0')z++;
                else o++;
            }
            if(z <= m && o <= n) updateMap(z,o,m,n,map);
        }
        
        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++) {
                ans = max(ans, map[i][t]);
            }
        }
        
        return ans;
    }
};