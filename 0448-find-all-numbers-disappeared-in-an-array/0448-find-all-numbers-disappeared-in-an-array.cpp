class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<bool> appear(n+1, 0);
        for(int i = 0; i < n; i++){
            appear[nums[i]] = true;
        }
        for(int i = 1; i <= n; i++){
            if(appear[i] == false)ans.push_back(i);
        }
        return ans;
        
    }
};