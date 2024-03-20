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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aP = list1;
        ListNode* bP;
        ListNode* p2 = list2;
        b = b-a;
        
        while(a-- > 1) aP = aP->next;
        bP = aP->next;
        while(b-- >= 0) bP = bP->next;
        //cout<< aP->val<<" "<<bP->val<<endl;
        aP->next = list2;
        while(p2->next != NULL)p2 = p2->next;
        p2->next = bP;
        return list1;
    }
};