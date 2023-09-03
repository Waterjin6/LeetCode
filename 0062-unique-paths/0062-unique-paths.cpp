class Solution {
public:
    int uniquePaths(int m, int n) {
        if((m == 1)&&(n == 1))return 1;
        if(m == 1)return 1;
        if(n == 1)return 1;
        
        long long ans = 1;


        int k = 2;
        
        if(m < n){
            int temp = m;
            m = n;
            n = temp;
        }
        
        for(int i = n + m - 2; i > m-1; ans *= i, i--){
            if(ans*i >= 2 * 1000000000){
                ans /= k;
                k++;
            }
        };
        
        for(; k <= n - 1; ans /= k, k++);

        return (int)ans;
    }
};