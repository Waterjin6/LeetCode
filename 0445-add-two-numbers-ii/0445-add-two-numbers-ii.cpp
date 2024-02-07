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
        stack<int> s1, s2, fin;
        int x1, x2, u = 0;
        
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        while(!s1.empty() && !s2.empty()){
            x1 = s1.top();
            x2 = s2.top();
            s1.pop();
            s2.pop();
            //cout<< x1<<" "<<x2<<" "<<u<<endl;
            fin.push((x1+x2+u)%10);
            if(x1+x2+u >= 10) u = 1;
            else u = 0;
        }
        
        while(!s1.empty()){
            fin.push((s1.top()+u)%10);
            if(s1.top()+u >= 10) u = 1;
            else u = 0;
            s1.pop();
        }
        
        while(!s2.empty()){
            fin.push((s2.top()+u)%10);
            if(s2.top()+u >= 10) u = 1;
            else u = 0;
            s2.pop();
        }
        if(u == 1)fin.push(1);
        ListNode* root = new ListNode(fin.top());
        ListNode* p = root;
        fin.pop();
        
        while(!fin.empty()){
            ListNode* np = new ListNode(fin.top());
            fin.pop();
            p->next = np;
            p = p->next;
        }
        
        return root;
        
    }
};