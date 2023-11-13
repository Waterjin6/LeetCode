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
    bool isPalindrome(ListNode* head) {
        vector<int> l;
        for(;head != nullptr; head = head->next)l.push_back(head->val);
        
        for(int i = 0; i < l.size()/2; i++){
            if(l[i] != l[l.size()-1-i])return false;
        }
        return true;
    }
};