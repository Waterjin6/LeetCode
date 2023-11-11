class Solution {
public:
    long long makeHappyNum(int n){
        long long ans = 0;
        
        while(n > 0){
            ans += (n%10)*(n%10);
            n /= 10;
        }

        return ans;
    }
    
    bool isHappy(int n) {
        int a = n, b = n;
        
        do{            
            //cout<< a <<" "<< b <<endl;
            a = makeHappyNum(a);
            if(a == 1)return true;
            b = makeHappyNum(makeHappyNum(b));
            
        }while(a != b);
        
        return false;
    }
};