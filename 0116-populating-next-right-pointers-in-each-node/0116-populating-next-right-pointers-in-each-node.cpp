/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        int child = 1, ch = 1;
        
        while(!q.empty()){
            vector<Node*> v;
            
            ch = 0;
            for(int i = 0; i < child; i++){
                Node* n = q.front();
                q.pop();
                v.push_back(n);
                
                if(n->left){
                    q.push(n->left);
                    //v.push_back(n->left);
                    ch++;
                }
                if(n->right){
                    q.push(n->right);
                    //v.push_back(n->right);
                    ch++;
                }
            }
            
            for(int i = 0; i < v.size()-1; i++){
                (v[i])->next = v[i+1];
            }
            /*for(int i = 0; i< v.size(); i++){
                cout<<v[i]->val<<" ";
            }
            cout<<endl;
            cout<< child<<endl;*/
            child = ch;
        }
        return root;
    }
};