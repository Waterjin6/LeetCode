class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        char b = chars[0];
        int c = 1;
        
        for(int i = 1; i < chars.size(); i++){
            if(b == chars[i])c++;
            else {
                //cout<< b<<" "<< to_string(c)<<endl;
                ans += b;
                if(c > 1)ans += to_string(c);
                b = chars[i];
                c = 1;
            }
        }
        ans += b;
        if(c > 1)ans += to_string(c);
        chars.clear();
        
        for(int i = 0; i < ans.length(); i++)chars.push_back(ans[i]);
        return ans.length();
    }
};