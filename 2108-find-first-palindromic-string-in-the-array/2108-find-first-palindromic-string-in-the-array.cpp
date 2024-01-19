class Solution {
public:
    bool isPalin(string & word){
        int wl = word.length();

        for(int i = 0; i < wl/2; i++){
            if(word[i] != word[wl-1-i])return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            if(isPalin(words[i]))return words[i];
        }
        return "";
    }
};