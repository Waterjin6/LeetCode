class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length(), tem, carry = 0;
        
        string ans(l1+l2, '0');
        
        for(int i = l1-1; i >= 0; i--){
            for(int t = l2-1; t >= 0; t--){
                tem = (ans[i+t+1]-'0') + (num1[i]-'0')*(num2[t]-'0')+carry;
                //cout<< "tem : "<<tem<<endl;
                ans[i+t+1] = (tem % 10) + '0';
                carry = tem / 10;
            }
            ans[i] = carry +'0';
            carry = 0;
            //cout<<ans<<endl;
        }
        
        int idx = 0;
        
        while(idx < ans.length() && ans[idx] == '0')idx++;
        cout<<idx<<endl;
        if(idx == ans.length())return "0";
        return ans.substr(idx);
    }
};