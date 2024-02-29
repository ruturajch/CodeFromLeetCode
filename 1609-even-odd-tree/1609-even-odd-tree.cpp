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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> hq;
        hq.push({root, 0});
        while(!hq.empty()){
            vector<int> helperVector;
            int leve = hq.front().second;
            while(leve == hq.front().second){
                auto temp = hq.front();
                hq.pop();
                helperVector.push_back(temp.first->val);
                if(temp.first->left != nullptr){
                    hq.push({temp.first->left, leve+1});
                }
                if(temp.first->right != nullptr){
                    hq.push({temp.first->right, leve+1});
                }
            }
            if(leve%2 == 0){
                int n = helperVector.size();
                int temp = helperVector[0];
                if(helperVector[0]%2 == 0){
                    return false;
                }
                for(int i = 1; i < n; i++){
                    if(helperVector[i] <= temp || helperVector[i]%2 == 0){
                        return false;
                    }
                    temp = helperVector[i];
                }
            }else{
                int n = helperVector.size();
                int temp = helperVector[0];
                if( helperVector[0]%2 == 1){
                    return false;
                }
                for(int i = 1; i < n; i++){
                    if(helperVector[i] >= temp || helperVector[i]%2 == 1){
                        return false;
                    }
                    temp = helperVector[i];
                }
            }
        }
        return true;
    }
};