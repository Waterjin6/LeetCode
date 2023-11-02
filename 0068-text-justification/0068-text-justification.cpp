class Solution {
public:
    string makeString(int st, int ed, int &width, vector<string>& words){
        vector<string> strs;
        int charSum = 0;
        string ans = "";
        
        for(int i = st; i <= ed; i++){
            strs.push_back(words[i]);
            charSum += words[i].length();
        }

        int space = width - charSum;
        int idx = 0;
        
        while(space > 0){
            strs[idx]+= " ";
            space--;
            idx = (idx + 1) % strs.size();
            if(idx == strs.size()-1)idx = 0;
        }
        
        for(int i = 0; i < strs.size(); i++){
            ans += strs[i];
        }
        
        return ans;
    }
    
    string makeFin(int st, int ed, int &width, vector<string>& words){
        int charSum = words[st].size();
        string ans = words[st];
        
        for(int i = st+1; i <= ed; i++){
            ans += " ";
            ans += words[i];
            charSum += words[i].length()+1;
        }

        int space = width - charSum;
        
        for(int i = 0; i < space; i++){
            ans.append(" ");
        }
        
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int sum = -1;
        int start = 0;
        
        for(int i = 0; i < words.size(); i++){
            if(sum + 1 + words[i].size() <= maxWidth){
                sum = sum + 1 + words[i].size();
            }
            else{
                //cout<< start << " "<< i-1 <<endl;
                ans.push_back(makeString(start, i-1, maxWidth, words));
                start = i;
                sum = words[i].size();
            }
        }
        //cout<< start<<endl;
        ans.push_back(makeFin(start, words.size()-1, maxWidth, words));
        
        return ans;
    }
};