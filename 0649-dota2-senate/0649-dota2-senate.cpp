class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dCon;
        queue<int> rCon;
        int idx = 0;
        for(; idx < senate.size(); idx++){
            if(senate[idx] == 'R')rCon.push(idx);
            else dCon.push(idx);
        }
        
        while(!dCon.empty() && !rCon.empty()){
            if(dCon.front() < rCon.front()){
                dCon.push(idx++);
            }
            else{
                rCon.push(idx++);
            }
            rCon.pop();
            dCon.pop();
        }
        
        if(dCon.empty())return "Radiant";
        return "Dire";
    }
};