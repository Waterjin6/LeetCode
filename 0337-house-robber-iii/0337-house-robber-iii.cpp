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
    unordered_map<TreeNode*, int> m;
    
    int rob(TreeNode* root) {
        int ans = 0;
        if(!root)return ans;
        if(m[root])return m[root];
        
        int rl = 0, rr = 0, rll = 0, rlr = 0, rrl = 0, rrr = 0;
        
        if(root->left){
            rl = rob(root->left);
            if(root->left->left) rll = rob(root->left->left);
            if(root->left->right) rlr = rob(root->left->right);
        }
        if(root->right){
            rr = rob(root->right);
            if(root->right->left) rrl = rob(root->right->left);
            if(root->right->right) rrr = rob(root->right->right);
        }
        ans = max(root->val+rll+rlr+rrl+rrr, rl+rr);
        if(!m[root]) m[root] = ans;
        
        return ans;
    }
};