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
    unordered_map<TreeNode*, int> sumT;
    unordered_map<TreeNode*, int> childN;
    
    void setSum(TreeNode* t){
        if(t == nullptr)return;
        
        childN[t] = 1;
        
        if(t->left) {
            setSum(t->left);
            childN[t] += childN[t->left];
        }
        if(t->right) {
            setSum(t->right);
            childN[t] += childN[t->right];
        }
        
        sumT[t] = sumT[t->left] + sumT[t->right] + t->val;
        
        return;
    }
    
    int averageOfSubtree(TreeNode* root) {
        setSum(root);
        int ans = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        for(auto i = sumT.begin(); i != sumT.end(); i++){
            TreeNode* n = i->first;
            if((childN[n] != 0)&&(sumT[n]/childN[n] == n->val)) ans++;
        }
        /*while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            
            int cnt = 1;
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);

            //cout<< sumT[n]/childN[n] << " "<< n->val <<endl;
            if(sumT[n]/childN[n] == n->val)ans++;
        }*/
        
        return ans;
    }
};