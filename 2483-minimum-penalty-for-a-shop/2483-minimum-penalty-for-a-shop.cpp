class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0;
        int minPen = customers.length();
        int pen = 0;
        int nY=0, nN=0, cN=0, cY=0;
        
        for(int i = 0; i < customers.length(); i++){
            if(customers[i] == 'Y')nY++;
        }
        
        nN = customers.length() - nY;
        
        cN = nN;
        cY = nY;
        
        for(int c = 0; c <= customers.length(); c++){
            pen = 0;
            int i = 0;
            
            if(c == customers.length())pen = nN;
            else if(c == 0)pen = nY;
            
            else 
            {
                if(customers[c-1] == 'Y') cY--;
                else cN--;
                
                pen += cY;
                pen += nN-cN;
            }
            
            if(pen < minPen){
                minPen = pen;
                ans = c;
            }
        }
        return ans;
    }
};