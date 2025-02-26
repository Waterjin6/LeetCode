class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> m;
        int sz = arr.size(), ans = 1;

        for(int i = 0; i < sz; i++){
            m[arr[i]] = m[arr[i]-difference] + 1;
            ans = max(m[arr[i]], ans);
        }

        return ans;
    }
};