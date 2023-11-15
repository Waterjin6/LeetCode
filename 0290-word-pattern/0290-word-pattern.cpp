#include <string>
#include <sstream>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> ms;
        unordered_map<char, string> mc;
        
        stringstream ss(s);
        string word;
        int i = 0;
        
        while(getline(ss, word, ' ')){
            if(ms.find(word) != ms.end() && ms[word] != pattern[i]) return false;
            if(mc.find(pattern[i]) != mc.end() && mc[pattern[i]] != word) return false;
            if(ms.find(word) == ms.end() && mc.find(pattern[i]) == mc.end()) {
                ms.insert({word, pattern[i]});
                mc.insert({pattern[i], word});
            }
            i++;
        }
        if(i < pattern.length())return false;
        return true;
    }
};