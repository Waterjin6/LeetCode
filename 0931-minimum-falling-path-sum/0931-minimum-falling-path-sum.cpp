class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int p = INT_MAX;
        int ms = matrix.size();
        
        for(int i = 1; i < ms; i++){
            for(int t = 0; t < ms; t++){
                p = INT_MAX;
                //cout<< "hey"<<endl;
                if(t-1 >= 0 && p > matrix[i-1][t-1]) {
                    //cout<<"first"<<endl;
                    p = matrix[i-1][t-1];
                }
                if(p > matrix[i-1][t])p = matrix[i-1][t];
                if(t+1 < ms && p > matrix[i-1][t+1]) p = matrix[i-1][t+1];
                //cout<< p <<endl;
                matrix[i][t] += p;
            }
        }
        
        for(int i = 0; i < ms; i++){
            ans = min(ans, matrix[ms-1][i]);
        }
        return ans;
    }
};