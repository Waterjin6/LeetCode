class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i = 0; i < arr.size(); i++){
            if(++m[arr[i]] > arr.size()/4)return arr[i];
        }
        return 0;
    }
};