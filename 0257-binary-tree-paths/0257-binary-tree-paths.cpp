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
    vector<string> ans;
    
    void getAns(TreeNode* n, string s){
        if(n == nullptr)return;
        s+= to_string(n->val);
        if(n->left == nullptr && n->right == nullptr){
            ans.push_back(s);
            return;
        }
        s+="->";
        getAns(n->left, s);
        getAns(n->right,s);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        getAns(root,s);
        return ans;
    }
};