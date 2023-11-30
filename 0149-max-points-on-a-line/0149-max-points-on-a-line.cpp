class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size() <= 2)return points.size();
        
        for(int i = 0; i < points.size()-1; i++){
            for(int t = i+1; t < points.size(); t++){
                int subAns = 2;
                
                double dx = points[i][0]-points[t][0];
                double dy = points[i][1]-points[t][1];
                //cout<<"dx : "<<dx <<", dy : "<<dy<<endl;
                
                for(int k = 0; k < points.size(); k++){
                    if(k == i || k == t)continue;
                    double ndx = points[i][0]-points[k][0];
                    double ndy = points[i][1]-points[k][1];
                    //cout<< ndx <<" "<<ndy<<endl;
                    if(ndx == 0){
                        if(dx == 0)subAns++;
                    }
                    else if(ndy == 0){
                        if(dy == 0)subAns++;
                    }
                    else if(dx/dy == ndx/ndy)subAns++;
                }
                
                if(subAns > ans) ans = subAns;
            }
        }
        
        return ans;
    }
};