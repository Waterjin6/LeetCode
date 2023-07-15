class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num;
        
        // 배열넣기
        for(int i = 0; i < m; i++)num.push_back(nums1[i]);
        for(int i = 0; i < n; i++)num.push_back(nums2[i]);
        
        sort(num.begin(),num.end()); // 정렬
        nums1 = num;
        /*
   
        nums1.clear();
        nums2.clear();
        

        for(int i = 0; i < m; i++)nums1.push_back(num[i]);
        for(int i = 0; i < n; i++){
            nums1.push_back(0);
            nums2.push_back(num[i]);
        }
        */
        return;
    }
};