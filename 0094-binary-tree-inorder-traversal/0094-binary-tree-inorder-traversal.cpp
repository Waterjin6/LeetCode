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
    vector<int> ans;
    
    void inorderTraval(TreeNode* t){
        if(t == NULL)return;
        
        if(t->left)inorderTraval(t->left);
        ans.push_back(t->val);
        if(t->right)inorderTraval(t->right);
        
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraval(root);
        
        return ans;
    }
};