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
    ListNode* doubleIt(ListNode* head) {
        ListNode* ans;
        stack<int> bef;
        stack<int> aft;
        int u = 0, n;
        
        for(;head; head = head->next) bef.push(head->val);
        //cout<< bef.size()<<endl;
        
        while(!bef.empty()){
            n = u + 2*bef.top();
            bef.pop();
            aft.push(n%10);
            u = n/10;
        }
        
        if(u > 0) aft.push(u);
        
        if(aft.size() == 0)return NULL;
        
        ans = new ListNode(aft.top());
        aft.pop();
        
        ListNode *p = ans;
        
        while(!aft.empty()){
            ListNode *n = new ListNode(aft.top());
            p->next = n;
            p = p->next;
            aft.pop();
        }
        return ans;
    }
};