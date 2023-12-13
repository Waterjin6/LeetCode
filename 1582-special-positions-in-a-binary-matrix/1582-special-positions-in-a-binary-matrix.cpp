class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int t = 0; t < mat[0].size(); t++){
                if(mat[i][t] == 1){
                    int cnt = 0;
                    for(int s = t+1; s < mat[0].size(); s++){
                        if(mat[i][s] == 1){
                            cnt = -1;
                            break;
                        }
                    }
                    if(cnt == -1)break;
                    for(int s = 0; s < mat.size(); s++){
                        if(mat[s][t] == 1)cnt++;
                    }
                    if(cnt == 1){
                        //cout << i <<" "<<t<<endl;
                        ans++;
                    }
                    break;
                }
                
            }
        }
        return ans;
    }
};