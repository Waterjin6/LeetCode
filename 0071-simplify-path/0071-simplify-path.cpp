class Solution {
public:
    string simplifyPath(string path) {
        while(path.length() > 1 && path[0] != '/')path.erase(0,1);
        if(path[path.length()-1] != '/') path += '/';
        stack<int> slash;
        slash.push(0);
        
        for(int i = 1; i < path.length();i++){
            if(path[i] == '/'){
                if(slash.top() == i-1){
                    //cout<< "a"<<endl;
                    path.erase(i,1);
                }
                else if(slash.top() == i-2 && path[i-1] == '.'){
                    //cout<<"y"<<endl;
                    path.erase(i-1, 2);
                }
                else if(slash.top() == i-3 && path.substr(i-2, 2) == ".."){
                    //cout<<"hey"<<endl;
                    path.erase(slash.top()+1,3);
                    i = slash.top();
                    if(slash.top() == 0)continue;
                    
                    slash.pop();
                    path.erase(slash.top()+1,i-slash.top());
                }
                else {
                    //cout<< "B"<<endl;
                    slash.push(i);
                }
                i = slash.top();
            }
        }
        
        while(path.length() > 1 && path[path.length()-1] == '/')path.erase(path.size()-1,1);
        
        return path;
    }
};