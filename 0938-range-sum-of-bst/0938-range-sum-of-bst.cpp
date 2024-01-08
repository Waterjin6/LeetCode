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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root == NULL)return ans;
        q.push(root);
        TreeNode *n;
        
        while(!q.empty()){
            n = q.front();
            q.pop();
            if(n->val >= low && n->val <= high) ans += n->val;
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }
        
        return ans;
    }
};