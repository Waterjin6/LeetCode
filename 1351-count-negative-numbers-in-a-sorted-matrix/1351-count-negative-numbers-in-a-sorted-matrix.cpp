class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, s, e, m;
        for(int i = 0; i < grid.size(); i++){
            s = 0;
            e = grid[i].size()-1;
            while(s <= e && grid[i][s] >= 0){
                m = (s+e)/2;
                if(grid[i][m] < 0) e = m-1;
                else s = m+1;
            }
            //cout<< s<<" "<<e<<endl;
            ans += grid[i].size()-s;
            
        }
        return ans;
    }
};