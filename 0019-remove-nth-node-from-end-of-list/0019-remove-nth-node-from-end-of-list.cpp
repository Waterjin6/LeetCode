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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0;
        
        for(ListNode *s = head; s != nullptr; s = s->next)listSize++;
        
        if(listSize == 1)return nullptr;
        
        int idx = listSize - n;
        
        //remove idx node
        if(idx == 0)return head->next;
        
        ListNode* p=head;
        for(int i = 0; i < idx-1; i++)p = p->next;
        
        p->next = p->next->next ;
        
        return head;
    }
};