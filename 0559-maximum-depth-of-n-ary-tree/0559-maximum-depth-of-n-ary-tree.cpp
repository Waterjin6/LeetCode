/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;
        if(!root)return ans;
        for(Node* n : root->children) ans = max(ans, 1+maxDepth(n));
        if(ans == 0)return 1;
        return ans;
    }
};