class Solution {
public:
    int findLUSlength(string a, string b) {
        int ans = 0, as = a.length(), bs = b.length();
        
        if(as != bs) return (as < bs) ? bs : as;
        if(a == b) return -1;
        return as;
        /*for(int sz = as; sz >= 1; sz--){
            for(int i = 0; i+sz <= as; i++){
                
            }
        }*/
        
        //return ans;
    }
};