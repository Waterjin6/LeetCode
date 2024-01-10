/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        map<int, TreeNode*> valAdd;
        map<TreeNode*, bool> isInfected;

        parent[root] = NULL;
        
        TreeNode* p = root;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            p = q.front();
            valAdd[p->val] = p;
            isInfected[p] = false;
            q.pop();
            
            if(p->left){
                parent[p->left] = p;
                q.push(p->left);
            }
            
            if(p->right){
                parent[p->right] = p;
                q.push(p->right);
            }
        }
        
        queue<TreeNode*> infected;
        
        int ans = -1, cnt = isInfected.size(), sz;
        //cout<<"cnt : "<<cnt<<endl;
        isInfected[valAdd[start]] = true;
        infected.push(valAdd[start]);
        
        TreeNode* a;
        
        while(!infected.empty()){
            sz = infected.size();
            //cout<< sz<<endl;
            for(int i = 0; i < sz; i++){
                a = infected.front();
                infected.pop();
                cnt--;
                if(a->left && isInfected[a->left] == false){
                    isInfected[a->left] = true;
                    infected.push(a->left);
                }
                if(a->right && isInfected[a->right] == false){
                    isInfected[a->right] = true;
                    infected.push(a->right);
                }
                if(parent[a] && isInfected[parent[a]] == false){
                    isInfected[parent[a]] = true;
                    infected.push(parent[a]);
                }
            }
            ans++;
            //cout<<"t : "<<ans <<", sz : "<<sz <<", cnt : "<<cnt<<endl;
            if(cnt == 0)break;
        }
        
        return ans;
    }
};