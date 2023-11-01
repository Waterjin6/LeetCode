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
    unordered_map<int,int> cnt;
    
    vector<int> ans;
    
    queue<TreeNode*> q;
    
    int findLargest(){
        int x = 0;
        
        for(auto i = cnt.begin(); i != cnt.end(); i++){
            if(i->second > x) x= i->second;
        }
        
        return x;
    }
    
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr)return ans;
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            cnt[n->val]++;
            //if(cnt.find(n->val) != cnt.end()) cnt[n->val]++;
            //else cnt.insert({n->val, 1});
            
            if(n->left)q.push(n->left);
            if(n->right)q.push(n->right);
        }
        
        int largest = findLargest();
        
        for(auto i = cnt.begin(); i != cnt.end(); i++){
            if(i->second >= largest)ans.push_back(i->first);
        }
        
        return ans;
    }
};