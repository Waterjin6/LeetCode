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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        if(head == nullptr || head->next == nullptr)return head;
        
        for(ListNode* h = head; h != NULL; h = h->next){
            m[h->val]++;
        }
        
        head = NULL;
        ListNode* q;
        
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second > 1)continue;
            ListNode* p = new ListNode(i->first);
            if(head == NULL){
                head = p;
                q = head;
            }
            else {
                q->next = p;
                q = q->next;
            }
        }

        return head;
    }
};