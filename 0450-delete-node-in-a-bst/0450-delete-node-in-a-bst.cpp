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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else{
            if(root->left == NULL && root->right == NULL) return NULL;
            else if(root->left == NULL)root = root->right;
            else if(root->right == NULL) root = root->left;
            else {
                TreeNode* lr = root->left;
                while(lr->right)lr = lr->right;
                //TreeNode* rl = root->right;
                //while(rl->left)rl = rl->left;
                
                /*if(rl == root->right){
                    root->val = rl->val;
                    root->right = deleteNode(root->right, rl->val);
                }*/
                //cout<< "lr : "<<lr->val<<endl;
                //else{
                    root->val = lr->val;
                    root->left = deleteNode(root->left, lr->val);
                //}
            }
        }
        return root;
    }
};