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
    int ans = INT_MIN;

    int takeOne(TreeNode* t){
        if(t == NULL) return 0;
        
        int tl = max(0,takeOne(t->left));
        int tr = max(0,takeOne(t->right));
        //cout<< "t->val : "<<t->val<< ", t->left : "<< tl <<", t->right : "<< tr<<endl;
        return t->val + max(tl,tr);
    }
    
    void updateAns(TreeNode* t){
        if(t == NULL) return;
        if(t->val > ans)ans = t->val;
        
        updateAns(t->left);
        updateAns(t->right);
        
        int tl = max(0,takeOne(t->left));
        int tr = max(0, takeOne(t->right));
        //cout<< "t->val : "<<t->val<< ", t->left : "<< tl <<", t->right : "<< tr<<endl;
        ans = max(ans, t->val + tl + tr);
        //cout<< "ans : "<<ans<<endl;
        
        return;
    }
    
    int maxPathSum(TreeNode* root) {
        updateAns(root);
        return ans;    
    }
};