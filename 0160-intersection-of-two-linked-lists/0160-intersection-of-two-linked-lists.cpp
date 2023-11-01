/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void insertSt(ListNode *hd, stack<ListNode*> &st){
        while(hd != nullptr){
            st.push(hd);
            hd = hd->next;
        }
        return;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> sA;
        stack<ListNode*> sB;
        
        insertSt(headA, sA);
        insertSt(headB, sB);
        
        ListNode* ans = nullptr;
        
        while((!sA.empty())&&(!sB.empty())){
            if(sA.top() != sB.top())break;
            
            ans = sA.top();
            
            sA.pop();
            sB.pop();
        }
        
        return ans;
    }
};