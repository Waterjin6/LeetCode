class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0, l1 = nums1.size(), l2 = nums2.size();
        
        while(i1 < l1 && i2 < l2){
            if(nums1[i1] < nums2[i2]) i1++;
            else if(nums1[i1] == nums2[i2])return nums1[i1];
            else i2++;
        }
        return -1;
    }
};