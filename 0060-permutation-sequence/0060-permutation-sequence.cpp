class Solution {
public:
    
    string getPermutation(int n, int k) {       
        string ans = "";
        string st = "";
        for(int i = 1; i <= n; i++)st +=to_string(i);
        
        int standard = 1;
        int sdDiv = n-1;
        
        for(int i = 1; i < n; i++)standard *= i;

        while(st.length() > 1){
            int idx = 0;
            while(k > standard * idx)idx++;
            idx--;
            
            k -= standard*idx;
            
            standard /= sdDiv;
            sdDiv--;
            
            ans += st[idx];
            st.erase(idx,1);
            
            //cout<<"k : "<<k<<endl;
            //cout<<"g : "<<standard<<endl;
            //cout<< "ans : "<<ans<<endl;
            //cout<< endl;
        }
        
        ans += st[0];
        
        return ans;
    }
};