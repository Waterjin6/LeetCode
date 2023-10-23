class Solution {
public:
    string rows[1000];
    int row = 0, icdc = 0;
    int numRows;
    
    void init_string(){
        for(int i = 0; i < numRows; i++){
            rows[i] = "";
        }
        return;
    }
    
    void append_ans(string &ans){
        for(int i = 0; i < numRows; i++){
            ans += rows[i];
        }
        return;
    }
    
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        
        this->numRows = numRows;
        
        init_string();
        
        for(int i = 0; i < s.length(); i++){
            rows[row] += s[i];
            
            if(icdc == 0)row++;
            else row--;
            
            if(row == -1){
                row = 1;
                icdc = 0;
            }
            else if(row == numRows){
                row = numRows-2;
                icdc = 1;
            }
        }
        
        string ans = "";
        
        append_ans(ans);
        
        return ans;
    }
};