class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1 +='.';
        version2 +='.';
        
        stringstream ss1(version1);
        stringstream ss2(version2);

        string s1, s2;
        int idx1 = 0, idx2 = 0;
        int n1, n2;
        
        while(true){
            s1 = "";
            s2 = "";
            
            getline(ss1, s1, '.');
            getline(ss2, s2, '.');
            if(s1 == "" && s2 == "") return 0;
            
            //idx1 = 0; idx2 = 0;
            
            //while(idx1 < s1.length() && s1[idx1] == '0')idx1++;
            //while(idx2 < s2.length() && s2[idx2] == '0')idx2++;
            
 
            //cout<< idx1<<" "<<idx2<<endl;
            //cout<< s1<<" "<<s2<<endl;
            n1 = (s1 == "") ? 0 : stoi(s1.substr(idx1));
            n2 = (s2 == "") ? 0 : stoi(s2.substr(idx2));
            //cout<< n1 <<" "<< n2<<endl;
            if(n1 > n2)return 1;
            else if(n1< n2)return -1;
        }

        return 0;
    }
};