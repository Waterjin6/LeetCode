class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> s;
        
        if(arr.size() == 1)return true;
        int b = arr[0], cnt = 1;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == b)cnt++;
            else{
                if(s.count(cnt) != 0)return false;
                s.insert(cnt);
                cnt = 1;
                b = arr[i];
            }
        }
        if(s.count(cnt) != 0)return false;
        return true;
    }
};