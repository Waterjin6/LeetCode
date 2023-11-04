class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int sec = 0;
        while(left.size()||right.size()){
            
            for(int i = 0; i < left.size();){
                if(left[i] == 0)left.erase(left.begin()+i);
                else i++;
            }
            
            for(int i = 0; i < left.size();i++)left[i]--;
            
            for(int i = 0; i < right.size();){
                if(right[i] == n)right.erase(right.begin()+i);
                else i++;
            }
            
            for(int i = 0; i < right.size();i++)right[i]++;
            
            sec++;
        }
        return sec-1;
    }
};