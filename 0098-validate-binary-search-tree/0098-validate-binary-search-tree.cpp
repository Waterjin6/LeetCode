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
    bool isValid(TreeNode* n, long mn, long mx){
        if(n == nullptr)return true;
  
        if (n->val <= mn)return false;
        if (n->val >= mx)return false;
        
        if(n->left){
            //if(n->val <= n->left->val)return false;
            if(isValid(n->left, mn, n->val) == false)return false;
        }
        if(n->right){
            //if (n->val >= n->right->val)return false;
            if(isValid(n->right, n->val, mx) == false)return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};