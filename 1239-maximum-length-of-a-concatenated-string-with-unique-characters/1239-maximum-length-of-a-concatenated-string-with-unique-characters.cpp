class Solution {
public:
    int ans = INT_MIN, sz;
    
    void updateAns(vector<int> cnt, int idx, int csz, vector<string>& arr){
        //cout<< idx <<endl;
        if(csz > ans) ans = csz;
        if(idx == sz)return;
        
        vector<int> nCnt = cnt;
        
        for(int i = idx; i < sz; i++){
            //cout<< i<<endl;
            bool flag = true;
            nCnt = cnt;
            
            for(int t = 0; t < arr[i].length(); t++){
                //cout<<arr[i][t]-'a'<<endl;
                if(nCnt[arr[i][t]-'a'] != 0){
                    //cout<<"hey"<<endl;
                    flag = false;
                    break;
                }
                else {
                    //cout<<"U"<<endl;
                    nCnt[arr[i][t]-'a']++;
                }
            }
            //cout<< i<<endl;
            if(flag == true)updateAns(nCnt, i+1, csz + arr[i].length(), arr);
        }
        return;
    }
    
    int maxLength(vector<string>& arr) {
        sz = arr.size();
        vector<int> cnt(26, 0);
        
        for(int i = 0; i < sz; i++) updateAns(cnt, i, 0, arr);
        return ans;
    }
};