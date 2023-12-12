class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> peaks;
        int b = 0, m = INT_MIN, ans = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[b] <= nums[i])b = i;
            else {
                peaks.push_back(b);
                b = i;
            }
        }
        peaks.push_back(b);
        for(int i = 0; i < peaks.size(); i++){
            if(nums[peaks[i]] > m){
                ans = peaks[i];
                m = nums[peaks[i]];
            }
        }
        
        return ans;
    }
};