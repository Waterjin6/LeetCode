class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        char l[3] = {'G', 'P', 'M'};
        
        for(int i = 0; i < 3; i++){
            char x = l[i];
            bool f = false;
            for(int r = garbage.size()-1; r >= 0; r--){
                for(int t = 0; t < garbage[r].size();){
                    if(x == garbage[r][t]){
                        garbage[r].erase(garbage[r].begin()+t);
                        ans++;
                        f = true;
                    }
                    else t++;
                }
                if(r > 0 && f == true) ans += travel[r-1];
            }
        }
        return ans;
    }
};