class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)return 1;
        
        int st = 2, ed = n-1, sumS = 1, sumE = n;
        //cout<< sumS<<" "<<sumE<<endl;
        
        while(st <= ed){
            while(sumS < sumE && st <= ed){
                sumS += st;
                st++;
            }
            while(sumE < sumS && st <= ed){
                sumE += ed;
                ed--;
            }
            //cout<< sumS<<" "<<sumE<<", st : "<<st<<" ed : "<<ed<<endl;
            if(sumS == sumE) {
                if(st == ed) return st;
                sumS += st;
                st++;
            }
        }
        return -1;
    }
};