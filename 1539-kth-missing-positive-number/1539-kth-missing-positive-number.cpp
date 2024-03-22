class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;
        int x = 1;
        
        for(int i = 0; i < arr.size() && ans.size() < k;){
            if(arr[i] == x) i++;
            else ans.push_back(x);
            x++;
        }
        
        while(ans.size() < k)ans.push_back(x++);
        
        return ans[k-1];
    }
};