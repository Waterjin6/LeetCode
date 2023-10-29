class Solution {
public:
    void sayWord(string &ans){
        string str = ""; 
        char f = ans[0];
        int cnt = 0;
        
        for(int i = 0; i < ans.length();){
            while((i < ans.length()&&(f == ans[i]))){
                cnt++;
                i++;
            }
            str += to_string(cnt);
            str += f;
            cnt = 0;
            if(i < ans.length())f = ans[i];
        }

        ans = str;
        return;
    }
    
    
    string countAndSay(int n) {
        string ans = "1";
        if(n == 1)return ans;
        
        for(int i = 2; i <= n; i++){ // n times
            sayWord(ans);
        }

        return ans;
    }
};