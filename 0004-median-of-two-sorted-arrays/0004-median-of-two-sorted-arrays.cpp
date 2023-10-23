class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        
        int midIdx, midSize;
        
        if((sz1 + sz2)%2 == 0){ // set midIdx, midSize
            midIdx = (sz1 + sz2)/2 - 1;
            midSize = 2;
        }
        else{
            midIdx = (sz1 + sz2)/2;
            midSize = 1;
        }
        
        double ans = 0;
        int idx1 = 0, idx2 = 0;
        //cout<<"midIdx : "<<midIdx<<endl;
        for(int i = 0; i < midIdx; i++){
            if(idx2 == sz2)idx1++;
            else if(idx1 == sz1)idx2++;
            else if(nums1[idx1] < nums2[idx2]) idx1++;
            else idx2++;
        }
        //cout<<"idx1 : "<<idx1<<", idx2 : "<<idx2<<endl;
        for(int i = 1; i <= midSize; i++){
            if(idx2 == sz2)ans += nums1[idx1++];
            else if(idx1 == sz1)ans += nums2[idx2++];
            else if(nums1[idx1] < nums2[idx2]) ans += nums1[idx1++];
            else {
                ans += nums2[idx2++];
            }
           // cout<<"ans : "<<ans<<endl;
        }
        
        return ans/midSize;
    }
};