class Solution {
public:
    static bool cmpBin(int a, int b){
        int cntA = 0, cntB = 0;
        int xa = a, xb =b;
        while(xa > 0){
            if(xa % 2 == 1)cntA++;
            xa -= xa%2;
            xa /= 2;
        }
        
        while(xb > 0){
            if(xb % 2 == 1)cntB++;
            xb -= xb%2;
            xb /= 2;
        }
        
        if(cntA < cntB) return true;
        if(cntB < cntA) return false;
        if(a < b)return true;
        return false;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),cmpBin);
        
        return arr;
    }
};