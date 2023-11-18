class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> a;
        for(int i = s.size()-1; i >= 0; i--)a.push_back(s[i]);
        s = a;
    }
};