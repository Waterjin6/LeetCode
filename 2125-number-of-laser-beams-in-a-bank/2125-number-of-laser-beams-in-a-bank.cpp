class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> sds;
        int ans = 0;
        
        for(int i = 0; i < bank.size(); i++){
            int p = 0;
            for(int t = 0; t < bank[i].size(); t++){
                if(bank[i][t] == '1')p++;
            }
            if(p > 0) sds.push_back(p);
        }
        if(sds.size() < 2)return ans;
        
        for(int i = 0; i < sds.size()-1; i++){
            //cout<<"hey"<<endl;
            ans += sds[i]*sds[i+1];
        }
        return ans;
    }
};