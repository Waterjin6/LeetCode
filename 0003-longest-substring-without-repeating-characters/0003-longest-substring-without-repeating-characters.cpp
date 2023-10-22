class Solution {
public:
    string s;
    int ans = 1;

    void updateAns(int st){
        int sum = 0;
        int cnt[256] = {0,0,0,};

        for(int i = st; i < s.length(); i++){
            if(cnt[s[i]] == 1) break;
            cnt[s[i]] = 1;
            sum++;
        }

        if(sum > ans) ans = sum;

        return;
    }

    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)return 0;
        this->s = s;

        for(int i = 0; (i < s.length()-1)&&(s.length() - i > ans); i++){
            updateAns(i);
        }

        return ans;
    }
};