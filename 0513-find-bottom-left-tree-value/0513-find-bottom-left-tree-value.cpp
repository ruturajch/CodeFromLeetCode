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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> helperQueue;
        helperQueue.push({root, 0});
        int ans = 0;
        while(!helperQueue.empty()){
            ans = helperQueue.front().first->val;
            int lev = helperQueue.front().second;
            
            while(lev == helperQueue.front().second){
                auto top = helperQueue.front().first;
                helperQueue.pop();
                if(top->left != nullptr)   
                    helperQueue.push({top->left, lev+1});
                if(top->right != nullptr)   
                    helperQueue.push({top->right, lev+1});
            }
        }
        return ans;
    }
};