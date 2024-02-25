class Solution {
public:
    bool isFascinating(int n) {
        string sn = "";
        for(int i = 1; i <= 3; i++) sn += to_string(n*i);
        
        int cnt[9] = {0};
        
        for(int i = 0; i < sn.length(); i++){
            //cout<< sn[i]-'0'<<endl;
            //cout<<cnt[sn[i]-'0'-1]<<endl;
            if(sn[i] == '0')continue;
            //cout<<cnt[sn[i]-'0'-1]<<endl;
            if(cnt[sn[i]-'0'-1]++ > 1)return false;
        }
        for(int i = 0; i < 9; i++){
            cout<< cnt[i]<<endl;
            if(cnt[i] != 1)return false;
        }
        return true;
    }
};