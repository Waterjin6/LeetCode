class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count = 0;
        
        for(int i = 0; i <= n; i++){
            count = 0;
            for(int k = i; k > 0; k /= 2){
                if(k % 2 == 1)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};