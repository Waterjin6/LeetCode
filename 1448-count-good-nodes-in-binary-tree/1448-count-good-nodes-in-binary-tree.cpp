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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        if(root == NULL)return ans;
        
        q.push({root, root->val});
        
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if(p.first->val >= p.second)ans++;
            if(p.first->left != NULL)q.push({p.first->left, max(p.second, p.first->left->val)});
            if(p.first->right != NULL)q.push({p.first->right, max(p.second, p.first->right->val)});
            
        }
        return ans;
    }
};