class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sx = 0, ex = matrix.size()-1, sy = 0, ey = matrix[0].size()-1;
        
        while(ex > 0 && matrix[ex][0] > target)ex--;
        //cout<< sx <<" "<<ex <<" "<< sy<<" "<< ey<<endl;
        while(sx < matrix.size()-1 && matrix[sx][ey] < target)sx++;
        //cout<< sx <<" "<<ex <<" "<< sy<<" "<< ey<<endl;
        if(sx > ex)return false;
        while(ex > 0 && matrix[sx][ey] > target)ey--;
        //cout<< sx <<" "<<ex <<" "<< sy<<" "<< ey<<endl;
        while(sy < matrix[0].size()-1 && matrix[ex][sy] < target)sy++;
        //cout<< sx <<" "<<ex <<" "<< sy<<" "<< ey<<endl;
        if(sy > ey)return false;
        for(int i = sx; i <= ex; i++){
            for(int t = sy; t <= ey; t++){
                if(matrix[i][t] == target)return true;
            }
        }
        return false;
    }
};