class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int mat = 1, zCnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)zCnt++;
            else mat *= nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(zCnt == 1)ans.push_back(mat);
                else ans.push_back(0);
            }
            else {
                if(zCnt > 0)ans.push_back(0);
                else ans.push_back(mat/nums[i]);
            }
        }
        return ans;
    }
};