class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int p = 0;
        for(int i = 1 ; i < arr.size(); i++){
            if(arr[i]<arr[p]){
                return p;
            }
            else p++;
        }
        return p;
    }
};