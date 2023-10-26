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
    ListNode* swapPairs(ListNode* head) {
        int size = 0;
        
        for(ListNode *p = head; p != nullptr; p=p->next)size++;
        
        if(size < 2)return head;
        
        ListNode *one = head;
        ListNode *two = head->next;
        ListNode *prv = nullptr;
        
        for(int i = 0; (i < size)&&(size - i >= 2); i += 2){
            //cout<< i<<endl;
            if(prv != nullptr)prv->next = two;
            one->next = two->next;
            two->next = one;
            if(one == head)head = two;
            
            prv = one;
            
            if(prv->next == nullptr)break;
            one = prv->next;
            two = prv->next->next;
        }
        
        return head;
    }
};