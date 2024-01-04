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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz = inorder.size();
        if(sz == 0)return NULL;
        TreeNode* root = new TreeNode(postorder[sz-1]);
        if(sz == 1)return root;
        
        int rIdx = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> il(inorder.begin(), inorder.begin()+rIdx);
        vector<int> pl(postorder.begin(),postorder.begin()+rIdx);
        //cout<< il.size()<<" "<<pl.size()<<endl;
        vector<int> ir(inorder.begin()+rIdx+1, inorder.end());
        vector<int> pr(postorder.begin()+rIdx,postorder.end()-1);
        //cout<< ir.size()<<" "<<pr.size()<<endl;
        TreeNode* l = buildTree(il,pl);
        TreeNode* r = buildTree(ir, pr);
        root->left = l;
        root->right = r;
        return root;
    }
};