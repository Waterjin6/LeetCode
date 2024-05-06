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
    ListNode* removeNodes(ListNode* head) {
        deque<int> dq;
        int sz, x;
        
        for(ListNode* p = head; p != NULL; p=p->next){
            while(!dq.empty() && dq.back() < p->val)dq.pop_back();
            dq.push_back(p->val);
        }
        
        if(dq.empty())return NULL;
        
        ListNode* root = new ListNode(dq.front());
        dq.pop_front();
        
        ListNode* bef = root;
        
        while(!dq.empty()){
            ListNode *p = new ListNode(dq.front());
            bef->next = p;
            dq.pop_front();
            bef = bef->next;
        }
        return root;
    }
};