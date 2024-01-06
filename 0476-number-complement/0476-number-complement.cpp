class Solution {
public:
    int findComplement(int num) {
        int ans = 0, t = 0;
        while(num > 0){
            if(num%2== 0) ans += pow(2,t);
            t++;
            num /= 2;
        }
        return ans;
    }
};