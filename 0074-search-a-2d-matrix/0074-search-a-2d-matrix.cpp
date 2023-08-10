class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if((target < matrix[0][0])&&(target > matrix[matrix.size()-1][matrix[matrix.size()-1].size()-1]))return false;
        
        int row = 0;
        while((row < matrix.size()-1)&&(target >= matrix[row+1][0]))row++;
        for(int col = 0 ; col < matrix[row].size(); col++)
            if(matrix[row][col] == target)return true;
        return false;
    }
};