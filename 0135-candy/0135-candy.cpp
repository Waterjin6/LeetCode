class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = ratings.size();
        int addCdy[20000] = {0};
        
        for(int i = 0; i < ratings.size(); i++){
            if(i > 0 && ratings[i-1] < ratings[i]) addCdy[i] = addCdy[i-1]+1;
            if(i < ratings.size()-1 && ratings[i+1] < ratings[i] && addCdy[i] == 0) addCdy[i]++;
            //ans += addCdy[i];
        }
        //for(int i = 0; i < 3; i++)cout<<addCdy[i]<<" ";
        //cout<<endl;
        for(int i = ratings.size()-1; i >= 0; i--){
            if(i < ratings.size()-1 && ratings[i+1] < ratings[i] && addCdy[i+1] >= addCdy[i]) addCdy[i] = addCdy[i+1]+1;
            ans += addCdy[i];
        }
        //for(int i = 0; i < 3; i++)cout<<addCdy[i]<<" ";
        //cout<<endl;
        
        return ans;
    }
};