class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alti;
        int max;
        alti.push_back(0);
        max = 0;
        for(int i = 0; i < gain.size(); i++){
            alti.push_back(alti[i] + gain[i]);
        }
        
        for(int i = 0; i < alti.size(); i++){
            if(max < alti[i]) max = alti[i];
        }
        return max;
    }
};