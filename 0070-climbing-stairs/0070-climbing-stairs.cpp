class Solution {
public:
    int climbS[46] = {0,};
    int climbStairs(int n) {
        if(n == 0)return 0;
        if(climbS[n] > 0)return climbS[n];
        
        if(n < 3){
            climbS[n] = n;
            return n;
        }
        
        climbS[n] = climbStairs(n-1) + climbStairs(n-2);
        return climbS[n];
    }
};