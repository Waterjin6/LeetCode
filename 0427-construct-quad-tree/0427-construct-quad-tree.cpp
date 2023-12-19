/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isOne(int x, int y, int sz, vector<vector<int>>& grid){
        int m = grid[x][y];
        
        for(int i = 0; i < sz; i++){
            for(int t = 0; t < sz; t++){
                if(m != grid[x+i][y+t])return false;
            }
        }
        return true;
    }
    
    Node* constr(int x, int y, int sz, vector<vector<int>>& grid){
        if(sz <= 0) return NULL;
        
        Node* root = new Node();
        
        if(isOne(x,y,sz,grid) || sz == 1){
            root->val = grid[x][y];
            root->isLeaf = true;
            return root;
        }
        
        int sSz = sz/2;
        
        root->topLeft = constr(x,y,sSz, grid);
        root->topRight = constr(x,y+sSz,sSz, grid);
        root->bottomLeft = constr(x+sSz, y, sSz, grid);
        root->bottomRight = constr(x+sSz,y+sSz,sSz, grid);
        root->val = root->topLeft->val || root->topRight->val || root->bottomLeft->val || root->bottomRight->val;
        
        return root;
    }
    
    
    Node* construct(vector<vector<int>>& grid) {
        Node* root = constr(0,0,grid.size(), grid);
        return root;
    }
};