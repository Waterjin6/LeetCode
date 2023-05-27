class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int unique = 1;
        
        for(int i = 0; i < nums.size(); i++){
            unique = 1;
            for(int t = 0; t < ans.size(); t++){
                if(nums[i] == ans[t]){
                    unique = 0;
                    break;
                }
            }
            if(unique == 1)ans.push_back(nums[i]);
        }
        nums = ans;
        /*for(int i = 0; i < ans.size(); i++){
            cout << ans[i]<< endl;
        }*/
        
        return ans.size();
    }
};