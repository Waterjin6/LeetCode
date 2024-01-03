class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int ss = spells.size(), ps = potions.size();
        sort(potions.rbegin(), potions.rend());
        
        vector<int> ans;
        
        
        for(int i = 0; i < ss; i++){
            int s = 0, e = ps-1, m;
            while(s <= e){
                m = (s+e)/2;
                //if(potions[m]- (success%spells[i]) >= (success / spells[i])) s = m+1;
                if(spells[i] > success/potions[m] || (spells[i] == success/potions[m] && success%potions[m] == 0)) s = m+1;
                //if(spells[i]*potions[m] >= (success-(success%spells[i]))) s = m+1;
                else e = m-1;
            }
            //cout<< s<<endl;
            ans.push_back(s);
        }
        return ans;
    }
};