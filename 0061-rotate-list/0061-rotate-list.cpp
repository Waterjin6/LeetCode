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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)return head;
        
        int size=0;
        
        stack<ListNode*> st;
        
        for(ListNode* i = head; i != nullptr; i = i->next){
            st.push(i);
            size++;
        }
        //cout<< size<<endl;
        k %= size;
        //cout<< "k : "<< k<<endl;
        ListNode* start = head;
        ListNode* befEnd;
        
        for(int i = 0; i < k; i++){
            ListNode* end = st.top();
            st.pop();
            befEnd = st.top();
            
            end->next = start;
            befEnd->next = nullptr;
            start = end;
        }
        
        return start;
    }
};