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
private:
    int dfs(TreeNode* root, string helperString){
        if(root->left == nullptr && root->right == nullptr){
            return stoi(helperString) * 10 +  root->val;
        }
        int sum = 0;
        if(root->left != nullptr){
            sum += dfs(root->left, helperString + to_string(root->val));
        }
        if(root->right != nullptr){
            sum += dfs(root->right, helperString + to_string(root->val));
        }
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, "0");
    }
};