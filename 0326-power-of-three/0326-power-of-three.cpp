class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n >= 3){
            //cout<< n%3<<endl;
            if(n % 3 > 0)return false;
            n /= 3;
        }
        //cout<< n<<endl;
        if(n == 1)return true;
        return false;
    }
};