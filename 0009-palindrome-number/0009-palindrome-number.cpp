class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if(x < 0)return false;
        for(int i = x; i > 0; i = i/10)arr.push_back(i%10);
        
        for(int i = 0; i < arr.size()/2; i++){
            if(arr[i] != arr[arr.size()-1-i])return false;
        }
        return true;
    }
};