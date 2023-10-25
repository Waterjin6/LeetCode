class Solution {
public:
    string ans = "";
    vector<pair<string, int>> dic;
    
    void makeDictionary(){
        dic.push_back(make_pair("M",1000));
        dic.push_back(make_pair("CM",900));
        
        dic.push_back(make_pair("D",500));
        dic.push_back(make_pair("CD",400));
        
        dic.push_back(make_pair("C",100));
        dic.push_back(make_pair("XC",90));
        
        dic.push_back(make_pair("L",50));
        dic.push_back(make_pair("XL",40));
        
        dic.push_back(make_pair("X",10));
        dic.push_back(make_pair("IX",9));
        
        dic.push_back(make_pair("V",5));
        dic.push_back(make_pair("IV",4));
        
        dic.push_back(make_pair("I",1));
        
        return;
    }
    
    int makeNum(int n){
        int dec = 0;
        for(int i = 0; i < dic.size(); i++){
            if(dic[i].second <= n){
                ans += dic[i].first;
                dec = dic[i].second;
                return dec;
            }
        }
        return dec;
    }
    
    string intToRoman(int num) {
        makeDictionary();
        
        while(num > 0){
            int decrease = makeNum(num);
            num -= decrease;
        }
        return ans;
    }
};