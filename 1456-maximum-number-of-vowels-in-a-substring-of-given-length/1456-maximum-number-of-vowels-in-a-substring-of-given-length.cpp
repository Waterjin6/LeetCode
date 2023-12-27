class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set<char> vowel = {'a','e','i','o','u'};
        vector<int> vCnt(s.length()+1, 0);
        int cnt = 0, ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(vowel.find(s[i]) != vowel.end())cnt++;
            vCnt[i+1] = cnt;
            if(i-k+1 >= 0) {
                //cout<< i<<" "<<i-k+1<<endl;
                //cout<< vCnt[i+1]<<" "<<vCnt[i-k+1]<<endl;
                ans = max(vCnt[i+1]-vCnt[i-k+1],ans);
            }
        }
        
        return ans;
    }
};