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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* n = head;
        int sz = 0;
        for(ListNode* t = head; t != NULL; t = t->next)sz++;
        if(sz == 1)return NULL;
        for(int i = 0; i < sz/2-1; i++)n=n->next;
        n->next = n->next->next;
        return head;
    }
};