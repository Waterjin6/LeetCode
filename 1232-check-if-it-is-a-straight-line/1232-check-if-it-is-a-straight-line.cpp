class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[0][0] - coordinates[1][0];
        int dy = coordinates[0][1] - coordinates[1][1];
        
        if(dx == 0){
            for(int i = 1; i < coordinates.size()-1; i++){
                if(coordinates[i][0] - coordinates[i+1][0] != 0 )return false;
            }
            return true;
        }
        if(dy == 0){
            for(int i = 1; i < coordinates.size()-1; i++){
                if(coordinates[i][1] - coordinates[i+1][1] != 0 )return false;
            }
            return true;
        }
        
        int rat = dy/dx;
        
        for(int i = 1; i < coordinates.size()-1; i++){
            if(coordinates[i][1] - coordinates[i+1][1] == 0 )return false;
            if(coordinates[i][0] - coordinates[i+1][0] == 0 )return false;
            if( (coordinates[i][1] - coordinates[i+1][1]) / (coordinates[i][0] - coordinates[i+1][0]) != rat )return false;
        }
        return true;
    }
};