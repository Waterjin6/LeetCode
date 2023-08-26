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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)return head;

        ListNode* beforeHead = NULL;
        ListNode* bLast;
        ListNode* afterHead = NULL;
        ListNode* aLast;
        
        ListNode* temp;
        
        while(head != NULL){ // initialization
            temp = new ListNode;
            temp->val = head->val;
            temp->next = NULL;
            
            if(head->val < x){
                if(!beforeHead){
                    beforeHead = bLast =temp;
                }
                else{
                    bLast->next = temp;
                    bLast = temp;
                }
            }
            else{
                if(!afterHead){
                    afterHead = aLast =temp;
                }
                else{
                    aLast->next = temp;
                    aLast = temp;
                }
            }
            
            head=head->next;
        }
        
        if(beforeHead){
            bLast->next = afterHead;
            return beforeHead;
        }
        return afterHead;
    }
};