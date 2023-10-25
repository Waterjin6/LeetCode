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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        
        if(nums.size() == 0)return root;
        
        int idx = nums.size()/2;
        root = new TreeNode(nums[idx]);
        
        vector<int> vl = vector<int>(nums.begin(), nums.begin()+idx);
        vector<int> vr = vector<int>(nums.begin()+idx+1, nums.end());
        
        root->left = sortedArrayToBST(vl);
        root->right = sortedArrayToBST(vr);
                             
        return root;
    }
};