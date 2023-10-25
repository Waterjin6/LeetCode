/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL)^(q == NULL))return false;
        if(p == NULL)return true;
        
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        
        pq.push(p);
        qq.push(q);
        
        while((pq.empty()==false)&&(qq.empty()==false)){
            TreeNode* pc = pq.front();
            TreeNode* qc = qq.front();
            
            pq.pop();
            qq.pop();
            
            if(pc->val != qc->val){
                cout<< "not same"<<endl;
                return false;
            }
            if((pc->left == NULL)^(qc->left == NULL)){
                cout<< "leftchild diff"<<endl;
                return false;
            }
            if(((pc->right) == NULL)^((qc->right) == NULL)){
                cout<< "right child diff"<<endl;
                return false;
            }
            
            if(pc->left)pq.push(pc->left);
            if(pc->right)pq.push(pc->right);
            
            if(qc->left)qq.push(qc->left);
            if(qc->right)qq.push(qc->right);
        }
        if((pq.empty()==false)||(qq.empty()==false)){
            cout<< "not empty"<<endl;
            return false;
        }
        return true;
    }
};