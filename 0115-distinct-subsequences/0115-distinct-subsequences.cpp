class Solution {
public:
    int can[1001][1001] = {{-1,}};
    
    int getAns(string &s, string &t, int si, int ti){
        int sum = 0;
        if(ti == t.length()){
            can[si][ti] = 1;
            return 1;
        }
        if(si == s.length()){
            can[si][ti] = 0;
            return 0;
        }
        if(can[si][ti] != -1) return can[si][ti];
        
        for(int i = si; i < s.length(); i++){
            if(s[i] == t[ti])sum += getAns(s,t,i+1, ti+1);
        }
        can[si][ti] = sum;
        
        return sum;
    }
    
    int numDistinct(string s, string t) {
        for(int i = 0; i < s.length(); i++){
            for(int k = 0; k < t.length(); k++){
                can[i][k] = -1;
            }
        }
        int ans = getAns(s,t, 0,0);
        return ans;    
    }
};