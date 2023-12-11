class Solution {
public:
    bool isPerfectSquare(int num) {
        vector<int> v;
        int i = 1;
        for(; i <= sqrt(INT_MAX) && i*i < num; i++);
        if(i <= sqrt(INT_MAX)&&i*i == num)return true;
        return false;
    }
};