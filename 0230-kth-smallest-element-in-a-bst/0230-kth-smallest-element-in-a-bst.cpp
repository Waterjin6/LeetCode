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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        queue<TreeNode*> q;
        
        q.push(root);
        TreeNode*t;
        
        while(!q.empty()){
            t = q.front();
            q.pop();
            pq.push(t->val);
            
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        
        for(int i = 1; i < k; i++)pq.pop();
        
        return pq.top();
    }
};