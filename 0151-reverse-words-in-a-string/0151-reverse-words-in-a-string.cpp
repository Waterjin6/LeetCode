class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        stringstream ss(s);
        string n, ans = "";
        
        while(getline(ss,n, ' ')){
            if(n != "")str.push_back(n);
        }
        
        for(int i = str.size()-1; i >= 1; i--)ans += str[i] +' ';
        ans += str[0];
        return ans;
    }
};