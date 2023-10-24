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
    queue<TreeNode*> q;
    vector<int> ans;
    
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)return ans;
        
        q.push(root);
        
        int nodeN = 1;
        
        while(!q.empty()){
            int largeN = -pow(2,31); 
            int child = 0;
            
            for(int i = 0; i < nodeN; i++){
                TreeNode *t = q.front();
                
                if(t->val > largeN) largeN = t->val;
                
                if(t->left){
                    q.push(t->left);
                    child++;
                }
                
                if(t->right){
                    q.push(t->right);
                    child++;
                }
                
                q.pop();
            }
            
            nodeN = child;
            
            ans.push_back(largeN);
        }
        
        return ans;
    }
};