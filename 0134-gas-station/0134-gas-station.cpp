class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gM = 0, gs = gas.size();
        
        for(int i = 0; i < gs; i++){
            gM = gas[i];
            if(gM == cost[i]){
                if(gs == 1)return i;
                continue;
            }
            int t = 1;
            for(; t < gs+1 && gM >= cost[(i+t-1)%gs]; t++){
                gM -= cost[(i+t-1)%gs];
                gM += gas[(i+t)%gs];
            }
            if(t == gs+1)return i;
            t = i;
        }
        return -1;
    }
};