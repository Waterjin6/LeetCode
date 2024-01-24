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
    int ans = 0;
    
    void check(TreeNode* n, vector<int> cnt){
        if(n == NULL)return;
        cnt[n->val]++;
        
        if(n->left == NULL && n->right == NULL){
            int mid = 0;
            for(int i = 1; i <= 9; i++) mid += cnt[i]%2;
            if(mid <= 1)ans++;
            return;
        }
        check(n->left, cnt);
        check(n->right, cnt);
        
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10, 0);
        check(root, cnt);
        return ans;
    }
};