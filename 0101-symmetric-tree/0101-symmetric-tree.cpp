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
    bool isSame(TreeNode* n1, TreeNode* n2){
        if(n1== nullptr ^ n2 == nullptr)return false;
        if(n1== nullptr && n2 == nullptr)return true;
        if(n1->val != n2->val)return false;
        
        return isSame(n1->left, n2->right) && isSame(n1->right, n2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)return true;
        //if(root->left == nullptr && root->right == nullptr)return true;
       // if(n1== nullptr ^ n2 == nullptr)return false;
        //if(!(root->left->val == root->right->val))return false;
        
        return isSame(root->left, root->right);
    }
};