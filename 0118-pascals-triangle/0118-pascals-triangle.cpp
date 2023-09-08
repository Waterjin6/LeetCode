class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int f1 = 1, l1 = 1;
        vector<vector<int>> answer;
        
        for(int i = 1; i <= numRows; i++){
            vector<int> row;
            row.push_back(f1);
            if(i > 2){
                for(int k = 1; k < i-1; k++)row.push_back(answer[i-2][k-1] + answer[i-2][k]);
            }
            if(i > 1)row.push_back(l1);
            
            answer.push_back(row);
        }
        
        return answer;
    }
};