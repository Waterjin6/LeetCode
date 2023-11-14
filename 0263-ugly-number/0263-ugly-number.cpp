class Solution {
public:
    bool isUgly(int n) {
        int p[3] = {2,3,5};
        while(n > 1){
            bool f = false;
            for(int i = 0; i < 3; i++){
                while(n % p[i] == 0){
                    n/= p[i];
                    f = true;
                }
            }
            if(f == false)return false;
        }
        if(n == 1)return true;
        return false;
    }
};