class Solution {
public:
    string to19[20] = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen", "Nineteen"};
    string ten[8] = {"Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string makeNum(int num){
        string s = "";
        if(num / 100 > 0) {
            s += to19[num/100]+" Hundred";
            num %= 100;
            if(num > 0)s += " ";
        }
        if(num <= 19 && num > 0) {
            s += to19[num];
            return s;
        }
        if(num / 10 > 0) {
            s += ten[num/10 - 2];
            num %= 10;
            if(num > 0)s += " ";
        }
        if(num > 0)s+= to19[num];
        return s;
    }
    
    string numberToWords(int num) {
        if(num == 0)return "Zero";
        string ans = "";
        
        if(num / 1000000000 > 0 ) {
            ans += makeNum(num / 1000000000)+" Billion";
            num %= 1000000000;
            if(num > 0)ans += " ";
        }
        if(num / 1000000 > 0){
            ans += makeNum(num / 1000000)+" Million";
            num %= 1000000;
            if(num > 0)ans += " ";
        }
        if(num / 1000 > 0){
            ans += makeNum(num / 1000)+" Thousand";
            num %= 1000;
            if(num > 0)ans += " ";
        }
        if(num > 0) ans += makeNum(num);
        return ans;
    }
};