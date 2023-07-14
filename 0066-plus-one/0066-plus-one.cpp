class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        bool isDone = false;
        
        int i = digits.size()-1;
        
        while(isDone == false){
            if(digits[i] < 9){ // 0~9
                digits[i]++;
                isDone = true;
            }
            else { // 9
                digits[i] = 0;
                
                if(i == 0){
                    digits.insert(digits.begin(),1);
                    isDone = true;
                }
                else{
                    i--;
                }
            }
        }
        return digits;
    }
};