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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int u = 0;
        int ans;
        ListNode* lans;
        ListNode* nxt;
        ListNode* lansHead;
        
        /*
        // 3. int to ListNode
        lans = new ListNode();
        lans->val = ( u + (l1->val + l2->val)) % 10;
        u = ( u + (l1->val + l2->val)) / 10;
        lansHead = lans;
        cout << lans->val;
        
        while(l1 && l2){
            nxt = new ListNode();
            lans->next = nxt;
            lans = lans->next;
            lans->val = ( u + (l1->val + l2->val)) % 10;
            u = ( u + (l1->val + l2->val)) / 10;
            lans = lans->next;
        }
        */
        // 3. int to ListNode
        lans = new ListNode();
        lans->val = ( u + (l1->val + l2->val)) % 10;
        u = ( u + (l1->val + l2->val)) / 10;
        lansHead = lans;
        l1 = l1->next;
        l2 = l2->next;
        
        
        while(l1 && l2){
            lans->next = new ListNode();
            lans = lans->next;
            lans->val = ( u + (l1->val + l2->val)) % 10;
            u = ( u + (l1->val + l2->val)) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            lans->next = new ListNode();
            lans = lans->next;
            lans->val = ( u + l1->val ) % 10;
            u = ( u + l1->val ) / 10;
            l1 = l1->next;
        }
        
         while(l2){
            lans->next = new ListNode();
            lans = lans->next;
            lans->val = ( u + l2->val ) % 10;
            u = ( u + l2->val ) / 10;
            l2 = l2->next;
        }
        
        if(u > 0){
            lans->next = new ListNode();
            lans = lans->next;
            lans->val = u;
        }
        
        // 4. return ListNode
        return lansHead;
    }
};