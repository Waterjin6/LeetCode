class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)return false;
        unordered_set<int> div;
        
        for(int x = 2; x*x <= num; x++){
            if(num % x == 0){
                div.insert(num/x);
                div.insert(x);
            }
        }

        for(auto x : div) num -= x;
        
        if(num == 1)return true;
        return false;
    }
};