class Solution {
public:
    int count[5][5] = { // a, e, i, o, u
        {0,1,0,0,0}, // a
        {1,0,1,0,0}, // e
        {1,1,0,1,1}, // i
        {0,0,1,0,1}, // o
        {1,0,0,0,0} // u
    };
    
    long ans[5] = {1,1,1,1,1};
    
    int modulo(int x){
        return x % 1000000007;
    }
    
    void work(){
        long arr[5] = {0,0,0,0,0};
        
        for(int i = 0; i < 5; i++){  // each ans row
            for(int t = 0; t < 5; t++){
                if(count[i][t] == 0)continue;
                arr[t] = modulo(arr[t] + ans[i]*count[i][t]);
            }
        }
        
        for(int i = 0; i < 5; i++)ans[i] = arr[i];
        
        return;
    }
    
    int countVowelPermutation(int n) {
        if(n == 1)return 5;
        
        for(int i = 1; i < n; i++){
            work();
        }
        
        int answer = 0;
        for(int i = 0; i < 5; i++){
            answer = modulo(ans[i] + answer);
        }
        return answer;
    }
};