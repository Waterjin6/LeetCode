/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isThere(TreeNode* root, TreeNode* n){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        while(!q.empty()){
            t = q.front();
            q.pop();
            //cout<< t->val<<" "<< n->val<<endl;
            if(t == n)return true;
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root)return root;
        
        if(root->left && root->right == NULL) return lowestCommonAncestor(root->left, p, q);
        if(root->right && root->left == NULL) return lowestCommonAncestor(root->right, p, q);
        
        if(isThere(root->left, p)){
            //cout<<"hey"<<endl;
            if(isThere(root->left, q))return lowestCommonAncestor(root->left, p, q);
            else if(isThere(root->right, q))return root;
            else return NULL;
        }
        else if(isThere(root->right, p)){
            if(isThere(root->right, q))return lowestCommonAncestor(root->right, p, q);
            else if(isThere(root->left, q))return root;
            else return NULL;
        }
        return NULL;
    }
};