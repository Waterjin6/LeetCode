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
    void makeV(vector<int> &v, TreeNode* t){
        if(t == NULL)return;
        v.push_back(t->val);
        makeV(v, t->left);
        makeV(v, t->right);
        return;
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        
        vector<int> v;
        makeV(v, root);

        //cout<< root->val<<endl;
        //cout<<root<<endl;
        
        TreeNode* p = root;
        
        for(int i = 1; i < v.size(); i++){
            TreeNode *t = new TreeNode(v[i]);
            p->left = NULL;
            p->right = t;
            p = p->right;
        }

        return;
    }
};