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
    int getNewNode(vector<ListNode*>& lists){
        int minX = 10001;
        int idx = -1;
        
        for(int i = 0; i < lists.size();){
            if(lists[i] == NULL){
                lists.erase(lists.begin()+i);
                continue;
            }
            if((lists[i])->val < minX){
                minX = (lists[i])->val;
                idx = i;
            }
            i++;
        }
        
        if(idx != -1)lists[idx] = (lists[idx])->next;
        
        return minX;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *p; 
        
        while(lists.size() > 0){
            int newN = getNewNode(lists);
            
            if(newN == 10001)continue;
            
            if(head == NULL){
                head = new ListNode();
                head->val = newN;
                head->next = NULL;
                p = head;
            }
            else{
                ListNode *n = new ListNode();
                n->val = newN;
                n->next = NULL;
                p->next = n;
                p = n;
            }
        }
        
        return head;
    }
};