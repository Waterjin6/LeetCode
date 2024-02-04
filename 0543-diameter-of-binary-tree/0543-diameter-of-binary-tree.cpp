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
    
    int getDepth(TreeNode* root){
        if(root == NULL)return 0;
        int ld = 0, rd = 0;
        ld = getDepth(root->left);
        rd = getDepth(root->right);
        return 1 + max(ld, rd);
    }
    
    void updateAns(TreeNode* r){
        if(r == NULL)return;
        int ld = 0, rd = 0;
        
        if(r->left){
            updateAns(r->left);
            ld = getDepth(r->left);
        }
        if(r->right){
            updateAns(r->right);
            rd = getDepth(r->right);
        }
        //cout<<ld <<" "<<rd<<endl;
        ans = max(ans, ld+rd);
        return;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        updateAns(root);
        return ans;
    }
};