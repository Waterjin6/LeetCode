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
//    vector<TreeNode*> ans;
    int sz;
//    vector<vector<TreeNode*>> dp(9, vector<TreeNode*>(9)));
    
    vector<TreeNode*> makeTree(int s, int e){
        if(s > e)return {NULL};
        
        vector<TreeNode*> ans;
        
        for(int i = s; i <= e; i++){
            vector<TreeNode*> left = makeTree(s, i-1);
            vector<TreeNode*> right = makeTree(i+1, e);
            
            for(int l = 0; l < left.size(); l++){
                for(int r = 0; r < right.size(); r++){
                    TreeNode* rt = new TreeNode(i);
                    rt->left = left[l];
                    rt->right = right[r];
                    ans.push_back(rt);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        sz = n;
        return makeTree(1, n);
    }
};