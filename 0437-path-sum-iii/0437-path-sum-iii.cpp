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
    int ans = 0;
    
    void getSum(TreeNode* root, long sum){
        if(sum == root->val)ans++;
        
        if(root->left) getSum(root->left, sum-root->val);
        if(root->right) getSum(root->right, sum-root->val);
        
        return;
    }
    
    void getAns(TreeNode* root, int sum){
        if(sum == root->val) ans++;
        
        if(root->left) {
            getSum(root->left, sum-root->val);
            getAns(root->left, sum);
        }
        if(root->right){
            getSum(root->right, sum-root->val);
            getAns(root->right, sum);
        }
        return;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root) getAns(root, targetSum);
        return ans;
    }
};