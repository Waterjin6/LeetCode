class Solution {
public:
    vector<int> ans;
    
    string getBin(int x){
        string xS = "";
        if(x == 0)return "0";
        while(x > 0){
            if(x % 2 == 0) xS.append("0");
            else xS.append("1");
            x/= 2;
        }
        
        reverse(xS.begin(), xS.end());
        
        return xS;
    }
    
    int getInt(string n){
        int x = 0;
        
        for(int i = 0; i < n.length(); i++){
            x += (n[i]-'0')*pow(2, n.length()-1-i);
            //cout<< "x : "<<x<<endl;
        }
        
        return x;
    }
    
    
    int getNext(int bef,int res){
        string n = "";
        //cout<< "bef : "<<bef<<endl;
        //cout<< "res : "<<res<<endl;
        string befS = getBin(bef);
        string resS = getBin(res);
        //cout<< "befS : "<<befS<<endl;
        //cout<< "res : "<<res<<endl;
        //cout<< "resS : "<<resS<<endl;
        int length = (befS.length() > resS.length()) ? befS.length() : resS.length();
        
        if(length > resS.length())resS.insert(0,length-resS.length(),'0');
        else if(length > befS.length())befS.insert(0, length-befS.length(),'0');
        
        //cout<< "befS : "<<befS<<endl;
        //cout<< "res : "<<res<<endl;
        //cout<< "resS : "<<resS<<endl;
        
        //cout<< "l : "<<length<<endl;
        for(int i = 0; i < length; i++){
            n.append(to_string((befS[i] - '0')^(resS[i]-'0')));
        }
        //cout<< n<<endl;
        int nInt = getInt(n);
        //cout<< "nInt: "<<nInt<<endl;
        //cout<<endl;
        
        return nInt;
    }
    
    vector<int> findArray(vector<int>& pref) {
        ans.push_back(pref[0]);
        
        if(pref.size() == 1)return ans;
        
        for(int i = 1; i < pref.size(); i++){
            int nextP = getNext(pref[i-1],pref[i]);
            ans.push_back(nextP);
        }
        
        return ans;
    }
};