class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)return dividend;
        
        if(divisor == -1){
            if(dividend == -pow(2,31)) return pow(2,31)-1;
            return dividend*divisor;
        }
        
        if(divisor == -pow(2,31)) {
            if(dividend == -pow(2,31))return 1;
            return 0;
        }
        
        bool isMinus = (dividend < 0)^(divisor < 0);
        
        int ans = 0;
        
        if(divisor < 0) divisor *= -1;
        
        if(dividend == -pow(2,31)){
            ans++;
            dividend = -(dividend + divisor);
        }
        else if(dividend < 0)dividend *= -1;
        
        while(dividend >= divisor){
            ans++;
            dividend -= divisor;
        }
        
        if(isMinus == true)ans *= -1;
        return ans;
    }
};