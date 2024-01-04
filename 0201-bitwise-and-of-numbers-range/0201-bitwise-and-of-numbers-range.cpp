class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = 0, ans = 0, p;
        if(left == right)return left;
        for(int x = right; x > 0; x /= 2)m++;
        //cout<<m<<endl;
        
        while(--m >= 0){
            //cout<<m<<" "<<left <<" "<<right<<endl;
            p = pow(2,m);
            if(left / p != right / p)break;
            if(left/p > 0)ans += p;
            left %= p;
            right %= p;
            //cout<<m<<" "<<left <<" "<<right<<endl;
        }
        return ans;
    }
};