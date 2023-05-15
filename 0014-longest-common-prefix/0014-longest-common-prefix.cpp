class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){//length of first word
            for(int t = 0; t < strs.size(); t++){ //num of words
                if(strs[0][i] != strs[t][i])return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};