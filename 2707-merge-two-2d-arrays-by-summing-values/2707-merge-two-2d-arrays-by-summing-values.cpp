class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int s1 = nums1.size(), s2 = nums2.size(), i1 = 0, i2 = 0;

        while(i1 < s1 && i2 < s2){
            if(nums1[i1][0] <= nums2[i2][0]) {
                if(ans.size() == 0 || nums1[i1][0] != ans[ans.size()-1][0])ans.push_back(nums1[i1]);
                else ans[ans.size()-1][1] += nums1[i1][1];
                i1++;
            }
            else {
                if(ans.size() == 0 || nums2[i2][0] != ans[ans.size()-1][0])ans.push_back(nums2[i2]);
                else ans[ans.size()-1][1] += nums2[i2][1];
                i2++;
            }
        }
        while(i1 < s1){
            if(ans[ans.size()-1][0] == nums1[i1][0]) ans[ans.size()-1][1] += nums1[i1][1];
            else ans.push_back(nums1[i1]);
            i1++;
        }
        while(i2 < s2){
            if(ans[ans.size()-1][0] == nums2[i2][0]) ans[ans.size()-1][1] += nums2[i2][1];
            else ans.push_back(nums2[i2]);
            i2++;
        }
        return ans;
    }
};