class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        
        stringstream ss(s);
        string sub;
        while(getline(ss, sub, ' ')){
            if(sub != "")ans++;
        }
        return ans;
    }
};