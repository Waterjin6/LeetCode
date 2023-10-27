class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int start = 0, end = nums.size()-1;
        
        if(nums.size() == 0)return ans;
        
        start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(start == end){
            ans[0] = -1;
            ans[1] = -1;
        }
        else{
            ans[0] = start;
            ans[1] = end-1;
        }
        /*
        // find start idx
        for(int s = start, e = nums.size()-1; s < nums.size();){
            if(s == e) {
                start = s+1;
                break;
            }
            
            int mid = (s + e) / 2;
            if(nums[mid] < target) s = mid;
            else if(nums[mid] >= target) e = mid - 1;
        }
        
        if(nums[start] == target)ans[0] = start;
        else ans[0] = -1;
        
        // find end idx
        for(int s = start, e = nums.size()-1; s < nums.size();){
            if(s == e) {
                end = e-1;
                break;
            }
            
            int mid = (s + e) / 2;
            if(nums[mid] <= target) s = mid+1;
            else if(nums[mid] > target) e = mid;
        }
        
        if(nums[end] == target)ans[1] = end;
        else ans[1] = -1;
        */
        return ans;
    }
};