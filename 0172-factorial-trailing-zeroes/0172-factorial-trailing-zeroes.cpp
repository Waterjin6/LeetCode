class Solution {
public:
    int trailingZeroes(int n) {
        int c2 = 0, c5 = 0, x;
        for(; n > 1; n--){
            x = n;
            while(x >= 10 && x % 10 == 0){
                c2++;
                c5++;
                x /= 10;
            }
            while(x >=5 && x % 5 == 0){
                c5++;
                x /= 5;
            }
            while(x >= 2 && x % 2 == 0){
                c2++;
                x /= 2;
            }
            //cout<< n <<" : c2 : "<< c2 <<" c5 : "<<c5<<endl;
        }
        return min(c2, c5);
    }
};