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
    vector<vector<int>> ans;
    
    void makePath(TreeNode* n, int targetSum, vector<int> v){
        if(n == NULL)return;
        v.push_back(n->val);
        //cout<< n->val<<" "<<targetSum<<endl;
        
        targetSum -= n->val;
        //if(targetSum < 0)return;
        
        if(n->left == NULL && n->right == NULL){
            if(targetSum == 0) ans.push_back(v);
            return;
        }
        
        makePath(n->left, targetSum, v);
        makePath(n->right, targetSum, v);
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        makePath(root, targetSum, v);
        return ans;
    }
};