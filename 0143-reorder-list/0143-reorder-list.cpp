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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        for(ListNode* p = head->next; p != NULL; p = p->next)v.push_back(p);
        
        int s = 0, e= v.size()-1;
        ListNode* l = head;
        
        while(s < e){
            l->next = v[e--];
            l = l->next;

            l->next = v[s++];
            l = l->next;
        }

        if(s == e){
            l->next = v[s];
            l = l->next;
        }
        l->next = NULL;
        
        return;
    }
};