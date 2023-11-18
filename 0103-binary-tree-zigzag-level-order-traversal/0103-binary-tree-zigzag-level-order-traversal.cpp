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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return ans;
        
        int child = 1;
        bool zg = 0;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> v;
            int nc = 0;
            
            for(int c = 0; c < child ; c++){
                TreeNode* t = q.front();
                q.pop();
                
                v.push_back(t->val);
                
                if(t->left){
                    q.push(t->left);
                    nc++;
                }
                if(t->right){
                    q.push(t->right);
                    nc++;
                }
            }
            child = nc;
            /*cout<< "zg : "<<zg<<endl;
            for(int i = 0; i < v.size(); i++)cout<< v[i]<<" ";
            cout<<endl;*/
            if(zg == 1){
                reverse(v.begin(),v.end());
                zg = 0;
            }
            else zg = 1;
            ans.push_back(v);
        }
        return ans;
    }
};