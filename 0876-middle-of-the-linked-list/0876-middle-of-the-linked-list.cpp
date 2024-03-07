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
    ListNode* middleNode(ListNode* head) {
        int sz = 0;
        for(ListNode* p = head; p ; p = p->next)sz++;
        //cout<< sz<<endl;
        
        for(int i = 0; i < sz/2; i++)head = head->next;
        return head;
    }
};