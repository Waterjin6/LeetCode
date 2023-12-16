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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        int x;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                t = q.front();
                q.pop();
                x = t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans.push_back(x);
        }
        return ans;
    }
};