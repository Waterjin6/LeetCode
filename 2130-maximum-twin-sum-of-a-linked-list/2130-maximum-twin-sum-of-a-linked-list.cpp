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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> num;
        int ans = INT_MIN;
        
        for(ListNode* h = head; h != NULL; h=h->next)num.push_back(h->val);
        for(int i = 0; i < num.size()/2; i++){
            ans = max(ans, num[i]+num[num.size()-1-i]);    
        }
        return ans;
    }
};