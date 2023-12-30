class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0};
        for(int i = 0; i < words.size(); i++){
            for(int t = 0; t < words[i].size(); t++)cnt[words[i][t]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] == 0)continue;
            if(cnt[i] % words.size() != 0)return false;
        }
        return true;
    }
};