class Solution {
public:
    void printMap(int &m, int &n, vector<vector<int>> &map){
        cout<<"PRINT============"<<endl;
        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++){
                if(map[i][t] > 0) cout << "zero : "<<i <<" one : "<< t << " : "<< map[i][t]<<endl;
            }
        }
        cout<<"================"<<endl<<endl;
        return;
    }
    void updateMap(int &z, int &o,int &m, int &n, vector<vector<int>> &map){
        vector<vector<int>> nMap(m+1, vector<int>(n+1, 0));
        
        //cout<< "z : "<< z<<" , o : "<<o <<endl;
        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++){
                if(map[i][t] > 0 && z+i <= m && o+t <= n) nMap[z+i][o+t] = map[i][t]+1;
            }
        }

        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++){
                if(nMap[i][t] > 0) map[i][t] = max(map[i][t],nMap[i][t]);
            }
        }
        map[z][o] = max(map[z][o], 1);
        return;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size(), z = 0, o = 0, ans = 0;
        vector<vector<int>> map(m+1, vector<int>(n+1, 0)); 
        
        for(int i = 0; i < sz; i++){ // 수 맞추기
            //cout<<"word : "<< strs[i]<<endl;
            z = 0;
            o = 0;
            for(char x : strs[i]){
                if(x == '0')z++;
                else o++;
            }
            if(z <= m && o <= n){
                updateMap(z,o,m,n,map);
                //printMap(m, n, map);
            }
        }
        
        for(int i = 0; i <= m; i++){
            for(int t = 0; t <= n; t++) {
                //cout << "zero : "<<i <<" one : "<< t << " : "<< map[i][t]<<endl;
                ans = max(ans, map[i][t]);
            }
        }
        
        return ans;
    }
};