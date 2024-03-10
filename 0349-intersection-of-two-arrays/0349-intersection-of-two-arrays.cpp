class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        nums1.erase(unique(nums1.begin(),nums1.end()), nums1.end());
        sort(nums2.begin(),nums2.end());
        nums2.erase(unique(nums2.begin(),nums2.end()), nums2.end());
        
        int n1 = 0, n2 = 0;
        vector<int> ans;
        
        while(n1 < nums1.size() && n2 < nums2.size()){
            if(nums1[n1] == nums2[n2]){
                ans.push_back(nums1[n1]);
                n1++;
                n2++;
            }
            else if(nums1[n1] > nums2[n2])n2++;
            else n1++;
        }
        
        return ans;
    }
};