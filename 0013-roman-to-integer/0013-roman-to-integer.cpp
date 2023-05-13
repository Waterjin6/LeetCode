class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        
        m.insert(make_pair('I', 1));
        m.insert(make_pair('V', 5));
        m.insert(make_pair('X', 10));
        m.insert(make_pair('L', 50));
        m.insert(make_pair('C', 100));
        m.insert(make_pair('D', 500));
        m.insert(make_pair('M', 1000));
        
       int sum = 0;
        
        for (int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    sum += 4;
                    i++;
                }
                else if(s[i+1] == 'X') {
                    sum += 9;
                    i++;
                }
                else{
                    sum += m[s[i]];
                }
            }
            else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    sum += 40;
                    i++;
                }
                else if(s[i+1] == 'C') {
                    sum += 90;
                    i++;
                }
                else{
                    sum += m[s[i]];
                }
            }
            else if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    sum += 400;
                    i++;
                }
                else if(s[i+1] == 'M') {
                    sum += 900;
                    i++;
                }
                else{
                    sum += m[s[i]];
                }
            }
            else{
                sum += m[s[i]];
            }
        }
        
        return sum;
    }
};