/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        if(head == NULL)return NULL;
        
        for(Node* n = head; n != NULL; n = n->next){
            if(m.find(n) == m.end()){
                Node* a = new Node(n->val);
                m[n] = a;
            }
        }
        
        for(Node* n = head; n != NULL; n = n->next){
            m[n]->next = m[n->next];
            m[n]->random = m[n->random];
        }
            
        return m[head];
    }
};