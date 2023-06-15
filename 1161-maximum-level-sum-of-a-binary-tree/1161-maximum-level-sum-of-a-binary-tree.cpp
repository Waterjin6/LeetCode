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

// 1. 레벨 구분
// 2. 레벨에 해당하는 원소들 합 넣기 : 돌면서 level count 값 올리는 함수 만들기 (입력함수)
// 3. 2가 가장 큰 값들 중에 제일 작은 레벨 값 return - 반복문 한번 돌면서 조건문 if val >

class Solution {
public:
    vector<pair<int, int>> levelChart;
    
    void pushLC(int lev, int num){
        int isExist = -1;
        for(int i = 0; i < levelChart.size(); i++){
            if (levelChart[i].first == lev){
                isExist = i;
                break;
            }
        }
        if(isExist == -1) levelChart.push_back(make_pair(lev, num));
        else levelChart[isExist].second += num;
    }
    
    void inputChart(TreeNode* node, int lev){
        pushLC(lev, node->val);
        if(node->left != NULL)inputChart(node->left, lev+1);
        if(node->right != NULL)inputChart(node->right, lev+1);
    }
    
    int maxLevelSum(TreeNode* root) {

        inputChart(root, 1);
        int ansLev = levelChart[0].first;
        int maxSum = levelChart[0].second;

        for(int i = 1; i < levelChart.size(); i++){
            if ((levelChart[i].second > maxSum)||((levelChart[i].second == maxSum)&&(levelChart[i].first < ansLev))){
                maxSum = levelChart[i].second;
                ansLev = levelChart[i].first;
            }
        }
        
        return ansLev;
    }
};