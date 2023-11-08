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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)return head;
        
        stack<int> st;
        for(;head != nullptr; head=head->next)st.push(head->val);
        
        ListNode* ansH = new ListNode(st.top());
        st.pop();
        ListNode* p = ansH;
        
        while(!st.empty()){
            ListNode *n = new ListNode(st.top());
            st.pop();
            
            p->next = n;
            p = p->next;
        }
        
        return ansH;
    }
};