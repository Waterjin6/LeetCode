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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        queue<tuple<TreeNode*, int, char>> q;
        
        if(root == NULL)return ans;
        q.push({root, 0, 'M'});
        
        while(!q.empty()){
            tuple<TreeNode*, int, char> t = q.front();
            q.pop();
            
            if(!(get<0>(t)->left)&&!(get<0>(t)->right)){
                ans = max(ans, get<1>(t));
            }
            if(get<0>(t)->left){
                if(get<2>(t) == 'L'){
                    ans = max(ans, get<1>(t));
                    q.push({get<0>(t)->left, 1, 'L'});
                }
                else {
                    q.push({get<0>(t)->left, get<1>(t)+1, 'L'});
                }
            }
            if(get<0>(t)->right){
                if(get<2>(t) == 'R'){
                    ans = max(ans, get<1>(t));
                    q.push({get<0>(t)->right, 1, 'R'});
                }
                else {
                    q.push({get<0>(t)->right, get<1>(t)+1, 'R'});
                }
            }
        }
        return ans;
    }
};