/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeBST(vector<int> v){
        if(v.size() == 0)return NULL;
        
        TreeNode* root = new TreeNode(v[v.size()/2]);
        vector<int> lv{v.begin(), v.begin()+v.size()/2};
        vector<int> rv{v.begin()+v.size()/2+1, v.end()};
        
        root->left = makeBST(lv);
        root->right = makeBST(rv);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        for(int i = 0; head != NULL; head = head->next)v.push_back(head->val);
        return makeBST(v);
    }
};