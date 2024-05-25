class Solution {
public:
    string convertToBase7(int num) {
        string minus = "", str = "";
        if(num < 0) {
            minus = '-';
            num *= -1;
        }
        
        while(num > 0){
            str += (num%7)+'0';
            num /= 7;
        }
        reverse(str.rbegin(), str.rend());
        if(str.size() == 0)str = '0';
        return minus + str;
    }
};