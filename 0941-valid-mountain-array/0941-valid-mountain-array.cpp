class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int b = -1, i = 0, as = arr.size();
        
        while(i < as && b < arr[i]) {
            b = arr[i++];
        }
        //cout<< i<<endl;
        if(i == 1 || i == as)return false;
        
        while(i < as && b > arr[i]){
            b = arr[i++];
        }
        //cout<< i<<endl;
        if(i != as)return false;
        return true;
    }
};