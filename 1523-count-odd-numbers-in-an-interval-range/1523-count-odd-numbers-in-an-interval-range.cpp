class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 == high % 2){
            if(low % 2 == 1) return (high-low+1)/2 + 1;
            else return (high-low+1)/2;
        }
        else return (high-low+1)/2;
    }
};