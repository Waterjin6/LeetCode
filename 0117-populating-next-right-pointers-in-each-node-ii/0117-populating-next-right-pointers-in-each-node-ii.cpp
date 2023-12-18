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
        Node* r = root;
        if(root == NULL)return root;
        
        deque<Node*> dq;
        dq.push_back(root);
        
        while(!dq.empty()){
            int dqSz = dq.size();
            for(int i = 0; i < dqSz; i++){
                Node* n = dq.front();
                dq.pop_front();
                if(i == dqSz-1) n->next = NULL;
                else n->next = dq.front();
                
                if(n->left)dq.push_back(n->left);
                if(n->right)dq.push_back(n->right);
            }
        }
        return root;
    }
};