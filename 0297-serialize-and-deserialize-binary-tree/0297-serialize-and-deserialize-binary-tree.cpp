/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "[]";
        string s = "[";
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(t == NULL) s += "NULL,";
            else {
                s+= to_string(t->val)+",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        s.erase(s.length()-1,1);
        s += "]";

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]")return NULL;
        stringstream ss(data.substr(1,data.length()-2));
        string s;
        
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            
            getline(ss, s, ',');
            if(s != "NULL"){
                TreeNode* l = new TreeNode(stoi(s));
                q.push(l);
                t->left = l;
            }
            
            getline(ss, s, ',');
            if(s != "NULL"){
                TreeNode* r = new TreeNode(stoi(s));
                q.push(r);
                t->right = r;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));