class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0, e = letters.size()-1, m;
        
        while(s <= e){
            m = (s+e)/2;
            if(letters[m] <= target) s = m+1;
            else e = m-1;
        }
        if(s >= letters.size())return letters[0];
        //cout<< letters[s]<<" "<<letters[e]<<endl;
        return letters[s];
    }
};