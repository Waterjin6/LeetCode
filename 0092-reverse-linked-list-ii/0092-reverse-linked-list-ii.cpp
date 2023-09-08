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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)return head;
        
        int num[right-left+1];
        
        ListNode* before;
        ListNode* p;
        
        if(left == 1) { // set before pointer
            before = nullptr;
            p = head;
        }
        else {
            before = head;
            for(int i = 1; i < left-1; i++)before = before->next;
            p = before->next;
        }
        
        ListNode* pHead = nullptr;
        ListNode* last;

        
        for(int i = right-left; i >= 0; i--){ // get reverse array
            num[i] = p->val;
            p = p->next;
        }
 
        ListNode* after = p;
        
        for(int i = 0; i < right-left+1; i++){ // make reverse linked list
            ListNode* n = new ListNode(num[i]);
            
            if(pHead == nullptr){
                pHead = n;
                last = n;
            }
            else{
                last->next = n;
                last = n;
            }
        }
        
        if(before) before->next = pHead; // link lists
        else head = pHead;
        if(after)last->next = after;
        
        return head;
    }
};