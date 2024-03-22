class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incomeCnt(n+1, 0);
        vector<bool> isBeliver(n+1, 0);
        
        for(int i = 0; i < trust.size(); i++){
            incomeCnt[trust[i][1]]++;
            isBeliver[trust[i][0]] = true;
        }
        
        for(int i = 1; i <= n; i++){
            if(isBeliver[i] == false && incomeCnt[i] == n-1)return i;
        }
        return -1;
    }
};