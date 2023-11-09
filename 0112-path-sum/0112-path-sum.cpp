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
    bool getTargetSum(TreeNode* root, int sum, int &target){
        if(root->left == nullptr && root->right == nullptr){
            if(target == sum + root->val)return true;
            return false;
        }
        bool l = false,r = false;
        if(root->left) l = getTargetSum(root->left, root->val + sum, target);
        if(root->right) r = getTargetSum(root->right, root->val + sum, target);
        
        return l || r;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        
        return getTargetSum(root,0, targetSum);
    }
};