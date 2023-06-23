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
    
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answer;
        ListNode* answerHead;
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val < list2->val){ // make head
            answer = new ListNode(list1->val);
            list1 = list1->next;
        }
        else{
            answer = new ListNode(list2->val);
            list2 = list2->next;
        }
        
        answerHead = answer;
        
        while((list1 != NULL)&&(list2 != NULL)){ // make chain
            if(list1->val < list2->val){
                ListNode * newNode;
                newNode = new ListNode(list1->val);
                answer->next = newNode;
                answer = answer->next;
                list1 = list1->next;
            }
            else{
                ListNode * newNode;
                newNode = new ListNode(list2->val);
                answer->next = newNode;
                answer = answer->next;
                list2 = list2->next;
            }
        }
        
        if(list1 != NULL)answer->next = list1;
        else answer->next = list2;

        return answerHead;
    }
};