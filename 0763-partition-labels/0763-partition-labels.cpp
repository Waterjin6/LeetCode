class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m(26, -1);
        vector<int> ans;
        int mx = 0, st = 0;
        
        for(int i = 0; i < s.length(); i++)m[s[i]-'a'] = i;
        
        for(int i = 0; i < s.length(); i++){
            mx = max(mx, m[s[i]-'a']);
            if(mx == i) {
                //cout<< s[i]<<endl;
                ans.push_back(mx-st+1);
                st = i+1;
            }
        }
        return ans;
    }
};