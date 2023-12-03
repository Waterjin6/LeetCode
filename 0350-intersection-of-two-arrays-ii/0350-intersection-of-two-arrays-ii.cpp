class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++){
            int fIdx = find(nums2.begin(),nums2.end(), nums1[i]) - nums2.begin();
            if(fIdx < nums2.size()){
                ans.push_back(nums1[i]);
                nums2.erase(nums2.begin()+fIdx);    
            }
        }
        return ans;
    }
};