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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)return head;
       // int size = 0;
        
       //for(ListNode* i = head; i != nullptr; i++)size++;
        
        int num[right-left+1];
        
        ListNode* before;
        ListNode* p;
        
        if(left == 1) {
            before = nullptr;
            p = head;
        }
        else {
            before = head;
            for(int i = 1; i < left-1; i++)before = before->next;
            cout<< "before: "<< before->val<<endl;
            p = before->next;
        }
        
        ListNode* pHead = nullptr;
        ListNode* last;

        
        for(int i = right-left; i >= 0; i--){
            num[i] = p->val;
            p = p->next;
        }
        
        for(int i = 0; i < right-left+1; i++)cout << num[i]<< " ";
        cout<< endl;
 
        ListNode* after = p;
        
        //cout<< "after: "<< after->val<<endl;
        for(int i = 0; i < right-left+1; i++){
            ListNode* n = new ListNode(num[i]);
            cout << "after"<<endl;
            cout << num[i]<< " ";
            cout << endl;
            
            if(pHead == nullptr){
                pHead = n;
                last = n;
            }
            else{
                last->next = n;
                last = n;
            }
        }
        cout<< "last: "<< last->val<<endl;
        
        if(before){
            before->next = pHead;
            pHead = head;
        }
        else before = pHead;
        if(after)last->next = after;
        
        return pHead;
    }
};