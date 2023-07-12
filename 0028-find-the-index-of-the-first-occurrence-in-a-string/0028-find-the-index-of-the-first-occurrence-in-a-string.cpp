class Solution {
public:
    int strStr(string haystack, string needle) {
        int founded = 0;

        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0]){
                founded = 1;
                for(int t = 0; t < needle.length(); t++){
                    if(haystack[i+t] != needle[t]){
                        founded = 0;
                        break;
                    }
                }
            }
            if(founded == 1)return i;
        }
        return -1;
    }
};