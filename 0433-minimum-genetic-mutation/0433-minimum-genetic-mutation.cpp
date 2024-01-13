class Solution {
public:
    int ans = INT_MAX;
    
    int diff(string &a, string &b){
        int ans = 0;
        
        for(int i = 0; i < 8; i++){
            if(a[i] != b[i])ans++;
        }
        return ans;
    }
    
    void checkIfPossible(int n, string &startGene, string &endGene, vector<string>& bank, vector<bool> isVisited){
        if(endGene == startGene){
            ans = min(ans, n);
            return;
        }
        
        for(int i = 0; i < bank.size(); i++){
            if(isVisited[i] == false && diff(startGene, bank[i]) == 1){
                isVisited[i] = true;
                checkIfPossible(n+1, bank[i], endGene, bank, isVisited);
                isVisited[i] = false;
            }
        }
        
        return;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<bool> isVisited(bank.size(), 0);
        
        for(int i = 0; i < bank.size(); i++){
            if(diff(startGene, bank[i]) == 1){
                isVisited[i] = true;
                checkIfPossible(1, bank[i],endGene, bank, isVisited);
                isVisited[i] = false;
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};