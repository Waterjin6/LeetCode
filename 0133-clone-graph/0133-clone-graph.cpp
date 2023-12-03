/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> m;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        queue<Node*> q;
        q.push(node);
        Node* start = new Node(node->val);
        if(m.find(node->val) == m.end()) m[node->val] = start;
        
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            
            for(int i = 0; i < (n->neighbors).size(); i++){
                Node* nd = new Node((n->neighbors)[i]->val);
                
                if(m.find((n->neighbors)[i]->val) == m.end()) {
                    m[(n->neighbors)[i]->val] = nd;
                    q.push((n->neighbors)[i]);
                }
                m[n->val]->neighbors.push_back(m[(n->neighbors)[i]->val]);
            }
        }
        
        return start;
    }
};