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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL || !root->left && !root->right)return sum;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t; 
        
        while(!q.empty()){
            t = q.front();
            q.pop();
            if(t->left){
                if(!t->left->left && !t->left->right)sum += t->left->val;
                else q.push(t->left);
            }
            if(t->right)q.push(t->right);
        }
        return sum;
    }
};