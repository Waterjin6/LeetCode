/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<pair<int, int>> pr;
    vector<int> ans;
    
    void makePair(TreeNode* root){
        if(!root) return;
        if(root->left){
            pr.push_back(make_pair(root->val, (root->left)->val));
            makePair(root->left);
        }
        if(root->right){
            pr.push_back(make_pair(root->val, (root->right)->val));
            makePair(root->right);
        }
    }
    
    void findNeighbor(int target, int k, int prv){
        if(k == 0){
            ans.push_back(target);
            return;
        }
        for(int i = 0; i < pr.size(); i++){
            if((target == pr[i].first)&&(prv != pr[i].second))findNeighbor(pr[i].second, k-1, target);
            if((target == pr[i].second)&&(prv != pr[i].first))findNeighbor(pr[i].first, k-1, target);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int t = k;
        
        // 1. make pair for all of matches
        makePair(root);
        
        //for(int i = 0; i < pr.size(); i++)cout << pr[i].first << pr[i].second << endl;
        
        // 2. find distance by while
        findNeighbor(target->val, k, 501);
        
        // 3. return answer
        return ans;
    }
};