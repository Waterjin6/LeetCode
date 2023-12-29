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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)return head;
        ListNode* o = NULL;
        ListNode* e = NULL;
        ListNode* on;
        ListNode* en;
        
        for(ListNode* t = head; t != NULL;){
            ListNode* n = new ListNode(t->val);
            if(n != NULL){
                if(e == NULL) {
                    e = n;
                    en = e;
                }
                else{
                    en->next = n;
                    en = en->next;
                }
            }
            t = t->next;
            
            if(t != NULL){
                ListNode* a = new ListNode(t->val);
                if(o == NULL){
                    o = a;
                    on = o;
                }
                else{
                    on->next = a;
                    on = on->next;
                }
            }
            if(t != NULL) t = t->next;
        }
        
        en->next = o;
        return e;
    }
};