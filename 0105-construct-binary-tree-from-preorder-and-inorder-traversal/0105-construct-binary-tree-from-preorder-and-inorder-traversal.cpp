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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //cout<< preorder.size()<<" "<<inorder.size()<<endl;
        if(preorder.size()==0 || inorder.size()==0)return NULL;
        int idx;
        
        for(int i = 0; i < inorder.size(); i++){
            if(preorder[0] == inorder[i]){
                idx = i;
                break;
            }    
        }
        TreeNode* root = new TreeNode(preorder[0]);
        
        if(preorder.size()==1 || inorder.size()==1)return root;
        
        preorder.erase(preorder.begin());
        vector<int> lp{preorder.begin(),preorder.begin()+idx};
        vector<int> li{inorder.begin(), inorder.begin()+idx};
        vector<int> rp{preorder.begin()+idx,preorder.end()};
        vector<int> ri{inorder.begin()+idx+1, inorder.end()};
        
        root->left = buildTree(lp,li);
        root->right = buildTree(rp, ri);
        
        return root;
    }
};