class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool up = false;
        
        for(int i = s.length()-1; i >= 1;){
            //cout<< i<<endl;
            if(up == true && s[i] == '1') i--;
            else if(up == true) s[i] = '1';
            else if(s[i] == '1') {
                up = true;
                s[i] = '0';
            }
            else {
                i--;
                up = false;
            }
            ans++;
        }
        return ans;
    }
};