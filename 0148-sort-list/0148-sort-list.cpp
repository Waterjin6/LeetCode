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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        for(ListNode* p = head; p != NULL; p = p->next)v.push_back(p->val);
        sort(v.begin(),v.end());
        int i = 0;
        for(ListNode* p = head; p != NULL; p = p->next)p->val = v[i++];
        return head;
    }
};