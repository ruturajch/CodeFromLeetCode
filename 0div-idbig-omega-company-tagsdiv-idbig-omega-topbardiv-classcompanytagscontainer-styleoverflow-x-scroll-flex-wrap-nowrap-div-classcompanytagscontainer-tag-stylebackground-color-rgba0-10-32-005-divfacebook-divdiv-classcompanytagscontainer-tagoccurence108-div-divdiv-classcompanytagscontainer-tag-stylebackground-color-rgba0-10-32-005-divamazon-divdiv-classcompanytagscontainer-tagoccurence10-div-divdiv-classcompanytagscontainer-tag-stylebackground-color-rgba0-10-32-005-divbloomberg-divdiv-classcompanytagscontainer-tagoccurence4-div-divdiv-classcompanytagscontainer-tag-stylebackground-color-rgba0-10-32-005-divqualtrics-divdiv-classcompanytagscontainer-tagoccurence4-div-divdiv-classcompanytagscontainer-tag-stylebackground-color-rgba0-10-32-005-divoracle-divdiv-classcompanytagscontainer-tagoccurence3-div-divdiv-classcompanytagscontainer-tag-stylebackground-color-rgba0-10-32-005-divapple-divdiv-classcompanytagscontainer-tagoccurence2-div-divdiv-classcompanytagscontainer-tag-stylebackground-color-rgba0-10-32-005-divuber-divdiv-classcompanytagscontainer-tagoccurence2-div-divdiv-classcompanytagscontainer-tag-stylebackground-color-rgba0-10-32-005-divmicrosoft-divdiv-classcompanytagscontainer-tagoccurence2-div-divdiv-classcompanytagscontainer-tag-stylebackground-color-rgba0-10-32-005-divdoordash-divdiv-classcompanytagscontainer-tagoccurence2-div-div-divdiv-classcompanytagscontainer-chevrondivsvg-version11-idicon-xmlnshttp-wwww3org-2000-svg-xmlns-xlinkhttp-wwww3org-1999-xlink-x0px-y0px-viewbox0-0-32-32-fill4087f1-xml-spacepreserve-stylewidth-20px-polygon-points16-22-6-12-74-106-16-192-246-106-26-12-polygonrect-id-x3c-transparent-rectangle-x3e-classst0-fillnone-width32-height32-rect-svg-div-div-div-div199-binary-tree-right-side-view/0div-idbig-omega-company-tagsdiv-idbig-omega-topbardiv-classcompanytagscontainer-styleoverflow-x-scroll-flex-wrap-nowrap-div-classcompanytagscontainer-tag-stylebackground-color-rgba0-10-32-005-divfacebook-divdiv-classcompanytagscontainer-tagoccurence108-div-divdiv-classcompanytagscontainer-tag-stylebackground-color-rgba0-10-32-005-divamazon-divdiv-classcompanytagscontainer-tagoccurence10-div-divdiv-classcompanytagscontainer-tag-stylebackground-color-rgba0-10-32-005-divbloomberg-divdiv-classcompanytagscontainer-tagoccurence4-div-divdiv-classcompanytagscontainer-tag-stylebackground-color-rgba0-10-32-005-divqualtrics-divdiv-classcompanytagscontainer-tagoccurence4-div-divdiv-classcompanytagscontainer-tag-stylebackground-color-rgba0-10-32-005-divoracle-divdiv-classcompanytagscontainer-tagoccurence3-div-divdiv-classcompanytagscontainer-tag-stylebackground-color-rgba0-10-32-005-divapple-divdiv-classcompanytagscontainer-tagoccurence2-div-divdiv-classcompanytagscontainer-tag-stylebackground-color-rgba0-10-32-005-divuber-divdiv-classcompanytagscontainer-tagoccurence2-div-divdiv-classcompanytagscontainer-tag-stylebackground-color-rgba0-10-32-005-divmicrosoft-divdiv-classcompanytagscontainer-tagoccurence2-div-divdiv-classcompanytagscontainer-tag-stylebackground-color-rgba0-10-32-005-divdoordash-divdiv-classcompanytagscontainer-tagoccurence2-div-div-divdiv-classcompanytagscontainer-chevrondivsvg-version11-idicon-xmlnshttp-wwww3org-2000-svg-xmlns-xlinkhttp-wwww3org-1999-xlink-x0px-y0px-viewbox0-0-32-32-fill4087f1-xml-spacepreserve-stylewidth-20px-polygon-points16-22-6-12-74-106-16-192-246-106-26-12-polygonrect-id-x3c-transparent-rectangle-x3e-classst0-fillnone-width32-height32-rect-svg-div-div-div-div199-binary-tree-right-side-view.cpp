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
    vector<int> rightSideView(TreeNode *root) {
    vector<int> ansVector;
    queue<pair<TreeNode*, int>> helperQueue;
    
    if (root != nullptr) {
        helperQueue.push({root, 0});
    }
    
    while (!helperQueue.empty()) {
        pair<TreeNode*, int> currNode = helperQueue.front();
        helperQueue.pop();
        
        if (currNode.first->left != nullptr) {
            helperQueue.push({currNode.first->left, currNode.second + 1});
        }
        if (currNode.first->right != nullptr) {
            helperQueue.push({currNode.first->right, currNode.second + 1});
        }
        
        // Check if this is the last node at its level
        if (helperQueue.empty() || helperQueue.front().second != currNode.second) {
            ansVector.emplace_back(currNode.first->val);
        }
    }
    
    return ansVector;
}

};