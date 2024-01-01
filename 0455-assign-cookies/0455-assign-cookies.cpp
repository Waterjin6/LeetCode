class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gi = 0, si = 0, ge = g.size()-1, se = s.size()-1, ans = 0;
        
        while(gi <= ge && si <= se){
            if(g[gi] <= s[si]){
                gi++;
                si++;
                ans++;
            }
            while(si <= se && gi <= ge && g[gi] > s[si])si++;
        }
        return ans;
    }
};