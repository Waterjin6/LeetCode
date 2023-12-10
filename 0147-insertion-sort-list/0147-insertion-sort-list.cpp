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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* h = new ListNode(head->val);
        head = head->next;
        
        while(head != NULL){
            ListNode* n = new ListNode(head->val);
            ListNode* b = h; 
            ListNode* a = h;
            while(a != NULL && a->val < n->val){
                b = a;
                a = a->next;
            }
            if(b == a){
                n->next = b;
                h = n;
            }
            else{
                b->next = n;
                n->next = a;
            }
            head = head->next;

        }
        return h;
    }
};