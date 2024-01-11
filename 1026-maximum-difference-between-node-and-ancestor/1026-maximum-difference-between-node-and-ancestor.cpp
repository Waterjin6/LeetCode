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
    
    pair<int,int> getRange(TreeNode* rt){
        pair<int,int> range = {rt->val, rt->val};
        
        if(rt->left){
            pair<int, int> l = getRange(rt->left);
            range.first = min(range.first, l.first);
            range.second = max(range.second, l.second);
        }
        
        if(rt->right){
            pair<int, int> r = getRange(rt->right);
            range.first = min(range.first, r.first);
            range.second = max(range.second, r.second);
        }
        ans = max(ans, abs(rt->val - range.first));
        ans = max(ans, abs(rt->val - range.second));

        return range;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)return ans;
        getRange(root);
        return ans;    
    }
};