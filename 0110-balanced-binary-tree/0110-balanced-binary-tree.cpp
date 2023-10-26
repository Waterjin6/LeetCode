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
    int getHeight(TreeNode* n){
        if(n == nullptr)return 0;
        int lh = (n->left != nullptr) ? getHeight(n->left) : 0;
        int rh = (n->right != nullptr) ? getHeight(n->right) : 0;
        
        if((lh == -1)||(rh == -1))return -1;
        if(abs(lh-rh) > 1)return -1;
        
        return (lh > rh) ? lh + 1 : rh + 1;
    
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)return true;
        //if((root->left == nullptr)&&(root->right == nullptr))return true;
        
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        
        if((lh == -1)||(rh == -1))return false;
        if(abs(lh-rh)<= 1)return true;
        return false;
    }
};