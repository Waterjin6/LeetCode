/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        ListNode* b;
        
        while(p->next){
            p->val = p->next->val;
            b = p;
            p = p->next;
        }
        b->next = NULL;
        return;
    }
};