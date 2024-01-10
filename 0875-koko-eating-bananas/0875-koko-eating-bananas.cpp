class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int ps = piles.size(), st = 1, ed = piles[ps-1], m, sh = 0;
        
        while(st <= ed){
            sh = 0;
            m = (st+ed)/2;
            for(int i = 0; i < ps&& sh <= h; i++){
                sh += piles[i]/m;
                if(piles[i] % m > 0)sh++;
            }
            if(sh <= h) ed = m-1;
            else st = m+1;
        }
        //cout<< st<<" "<<ed<<endl;
        return st;
    }
};