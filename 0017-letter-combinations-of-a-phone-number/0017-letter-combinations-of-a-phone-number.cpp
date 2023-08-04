class Solution {
public:
    vector<string> ans;
    string alphabet[8] = {"abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void getCombination(string &digits, int &totalLength, int currLength, string str){
        if(currLength == totalLength)
        {
            ans.push_back(str);
            return;
        }
        
        for(int i = 0; i < alphabet[digits[currLength] - '0' - 2].size(); i++){
            getCombination(digits, totalLength, currLength+1, str + alphabet[digits[currLength] - '0' - 2][i]);
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")return ans;

        int totalLength = digits.size();
        string digi = digits;
        
        string str;
        
        getCombination(digits, totalLength, 0, str);
        
        return ans;
    }
};