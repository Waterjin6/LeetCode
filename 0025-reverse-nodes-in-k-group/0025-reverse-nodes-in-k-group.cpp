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
    void reverseNode(ListNode* &sHead, int k) {
        vector<int> num;
        ListNode* n = sHead;
        for(int i = 0; i < k; i++, n=n->next)num.push_back(n->val);
        
        for(int i = 0; i < k; i++){
            sHead->val = num[num.size()-i-1];
            sHead = sHead->next;
        }
        return;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int listSize = 0;
        
        for(ListNode* s = head; s != nullptr; s = s->next)listSize++;
        ListNode* p = head;
        
        for(int i = 0; i+k <= listSize; i += k){
            reverseNode(p, k);
        }
        
        return head;
    }
};