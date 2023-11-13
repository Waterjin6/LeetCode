class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelIdx;
        char vowelList[10] = {'A','E', 'I','O','U','a','e','i','o','u'};
        map<char, int> vowelCnt;
        
        for(int i = 0; i < s.length(); i++){
            for(int v = 0; v < 10; v++){
                if(s[i] == vowelList[v]){
                    vowelCnt[s[i]]++;
                    vowelIdx.push_back(i);
                    break;
                }
            }
        }
        
        /*for(int i = 0; i < vowelIdx.size(); i++){
            cout<< vowelIdx[i]<<" ";
        }
        cout<<endl;*/
        int idx = 0;
        
        for(int i = 0; i < vowelIdx.size(); i++){
            while(vowelCnt[vowelList[idx]] == 0)idx++;
            s[vowelIdx[i]] = vowelList[idx];
            vowelCnt[vowelList[idx]]--; 
        }
        
        return s;
    }
};