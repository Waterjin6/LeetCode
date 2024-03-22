class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        int sz = questions.size();
        vector<long long> maxi(sz, 0);
        
        for(int i = sz-1; i >= 0; i--){
            maxi[i] = questions[i][0]; // own value
            if(i+questions[i][1]+1 < sz) maxi[i] += maxi[i+questions[i][1]+1]; // maxinum in range
            if(i+1 < sz && maxi[i] < maxi[i+1]) maxi[i] = maxi[i+1]; // maximun from now on
        }
        
        for(long long x : maxi) ans = max(x , ans);
        return ans;
    }
};