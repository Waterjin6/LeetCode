class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length();
        if(s3.length() == 0)return true;
        if(l1 == 0) return s2 == s3;
        if(l2 == 0) return s1 == s3;
        if(l1+l2 < s3.length())return false;
        
        vector<vector<bool>> ans(l1+1, vector<bool>(l2+1, 0));
        
        ans[0][0] = 1;
        
        for(int i = 1; i <= l1; i++){
            ans[i][0] = ans[i-1][0] && s3[i-1] == s1[i-1];
        }
        for(int i = 1; i <= l2; i++){
            ans[0][i] = ans[0][i-1] && s3[i-1] == s2[i-1];
        }
        
        for(int i = 1; i <= l1; i++){
            for(int t = 1; t <= l2; t++){
                /*if(ans[i-1][t] && s3[i+t-1] == s1[i-1])cout<< "one"<<endl;
                else if(ans[i][t-1] && s3[i+t-1] == s2[t-1]){
                    cout<< "two"<<endl;
                    cout<< "i : "<< i<< ", t : "<<t<<endl;
                    cout<<"ans[i][t-1] : "<< ans[i][t-1]<<endl;
                    cout<<"s3[i+t-1] : "<< s3[i+t-1]<<endl;
                }*/
                ans[i][t] = (ans[i-1][t] && s3[i+t-1] == s1[i-1])||(ans[i][t-1] && s3[i+t-1] == s2[t-1]);
            }
        }
        /*for(int i = 0; i <= l2; i++){
            for(int t = 0; t <= l1; t++){
                cout<< ans[t][i]<<" ";
            }
            cout<<endl;
        }*/
        return ans[l1][l2];
    }
};