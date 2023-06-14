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
    int minDiff = 100000;
    vector<int> arr;
    
    void insertVal(TreeNode* node){
        arr.push_back(node->val);
        if(node->left != NULL)insertVal(node->left);
        if(node->right != NULL)insertVal(node->right); 
    }
    
    int getMinimumDifference(TreeNode* root) {
        insertVal(root);
        
        sort(arr.begin(),arr.end());
        
        for(int i = 0 ; i < arr.size()-1; i++){
            if(arr[i+1] - arr[i] < minDiff)minDiff = arr[i+1] - arr[i];
        }
        
        return minDiff;
    }
};