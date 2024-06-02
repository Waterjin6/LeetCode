class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> div;
        
        for(int x = 1; x*x <= num; x++){
            if(num % x == 0){
                div.insert(num/x);
                div.insert(x);
            }
        }
        cout<< num<<endl;
        num += num;
        for(auto x : div){
            num -= x;
        }
        //cout<< num<<endl;
        if(num == 0)return true;
        return false;
    }
};