class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1Idx = 0, n2Idx = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.erase(unique(nums1.begin(),nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()), nums2.end());
        
        while(n1Idx < nums1.size() && n2Idx < nums2.size()){
            if(nums1[n1Idx] < nums2[n2Idx]){
                n1Idx++;
            }
            else if(nums1[n1Idx] > nums2[n2Idx]){
                n2Idx++;
            }
            else{
                nums1.erase(nums1.begin()+n1Idx);
                nums2.erase(nums2.begin()+n2Idx);
            }
        }
        
        vector<vector<int>> ans;
        ans.push_back(nums1);
        ans.push_back(nums2);
        return ans;
    }
};