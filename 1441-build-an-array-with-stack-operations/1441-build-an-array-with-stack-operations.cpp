class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int idx = 0;
        vector<string> ans;
        
        for(int i = 1; i <= n;i++){
            ans.push_back("Push");
            if(target[idx] != i){
                ans.push_back("Pop");
            }
            else idx++;
            if(idx >= target.size())break;
        }
        
        return ans;
    }
};