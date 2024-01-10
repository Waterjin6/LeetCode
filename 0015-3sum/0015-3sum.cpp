class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int ns = nums.size(), x, f, b;
        for(int i = 0; i < ns-2; i++){
            //cout<< nums[i]<<endl;
            x = -nums[i];
            f = i+1;
            b = ns-1;
            while(f < b){
                if(nums[f]+nums[b] == x){
                    ans.push_back({nums[i], nums[f],nums[b]});
                    f++;
                    b--;
                }
                else if(nums[f]+nums[b] < x) f++;
                else b--;
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};