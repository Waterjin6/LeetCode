class Solution {
public:
    long long tree[1000] = {0,};
    
    long long addTreeNum(int idx, vector<int>& arr){
        if(tree[idx] != 0)return tree[idx];
        
       long long totalNum = 1;
        
        if(idx < 1){
            tree[idx] = 1;
            return tree[idx];
        }
        
        for(int f = 0; (f < idx)&&(arr[f] <= sqrt(arr[idx])); f++){
            if(arr[idx] % arr[f] != 0)continue;
            long long myN = arr[idx]/arr[f];
 
            for(int s = f; (s < idx)&&(arr[s] <= myN); s++){
                if(arr[s] == myN){
                    if(f == s)totalNum += addTreeNum(f,arr)*addTreeNum(f,arr);
                    else{totalNum += 2*addTreeNum(f,arr)*addTreeNum(s,arr);}
                    break;
                }
            }
        }
        
        tree[idx] = totalNum;
        
        return tree[idx];
        
    }
    
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans = 0;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++){
            long long treeN = addTreeNum(i, arr);
            ans += treeN;
        }
        
        return ans % 1000000007;
    }
};