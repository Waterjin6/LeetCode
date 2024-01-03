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
    vector<int> getLeaf(TreeNode* r){
        vector<int> ans;
        if(r == NULL)return ans;
        
        stack<TreeNode*> st;
        st.push(r);
        TreeNode* t;
        
        while(!st.empty()){
            t = st.top();
            st.pop();
            if(t->left == NULL && t->right == NULL) {
                ans.push_back(t->val);
            }
            if(t->right) st.push(t->right);
            if(t->left) st.push(t->left);
        }
        return ans;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1 = getLeaf(root1);
        vector<int> r2 = getLeaf(root2);
        
        if(r1.size() != r2.size())return false;
        
        for(int i = 0; i < r1.size(); i++){
            if(r1[i] != r2[i])return false;
        }
        return true;
    }
};