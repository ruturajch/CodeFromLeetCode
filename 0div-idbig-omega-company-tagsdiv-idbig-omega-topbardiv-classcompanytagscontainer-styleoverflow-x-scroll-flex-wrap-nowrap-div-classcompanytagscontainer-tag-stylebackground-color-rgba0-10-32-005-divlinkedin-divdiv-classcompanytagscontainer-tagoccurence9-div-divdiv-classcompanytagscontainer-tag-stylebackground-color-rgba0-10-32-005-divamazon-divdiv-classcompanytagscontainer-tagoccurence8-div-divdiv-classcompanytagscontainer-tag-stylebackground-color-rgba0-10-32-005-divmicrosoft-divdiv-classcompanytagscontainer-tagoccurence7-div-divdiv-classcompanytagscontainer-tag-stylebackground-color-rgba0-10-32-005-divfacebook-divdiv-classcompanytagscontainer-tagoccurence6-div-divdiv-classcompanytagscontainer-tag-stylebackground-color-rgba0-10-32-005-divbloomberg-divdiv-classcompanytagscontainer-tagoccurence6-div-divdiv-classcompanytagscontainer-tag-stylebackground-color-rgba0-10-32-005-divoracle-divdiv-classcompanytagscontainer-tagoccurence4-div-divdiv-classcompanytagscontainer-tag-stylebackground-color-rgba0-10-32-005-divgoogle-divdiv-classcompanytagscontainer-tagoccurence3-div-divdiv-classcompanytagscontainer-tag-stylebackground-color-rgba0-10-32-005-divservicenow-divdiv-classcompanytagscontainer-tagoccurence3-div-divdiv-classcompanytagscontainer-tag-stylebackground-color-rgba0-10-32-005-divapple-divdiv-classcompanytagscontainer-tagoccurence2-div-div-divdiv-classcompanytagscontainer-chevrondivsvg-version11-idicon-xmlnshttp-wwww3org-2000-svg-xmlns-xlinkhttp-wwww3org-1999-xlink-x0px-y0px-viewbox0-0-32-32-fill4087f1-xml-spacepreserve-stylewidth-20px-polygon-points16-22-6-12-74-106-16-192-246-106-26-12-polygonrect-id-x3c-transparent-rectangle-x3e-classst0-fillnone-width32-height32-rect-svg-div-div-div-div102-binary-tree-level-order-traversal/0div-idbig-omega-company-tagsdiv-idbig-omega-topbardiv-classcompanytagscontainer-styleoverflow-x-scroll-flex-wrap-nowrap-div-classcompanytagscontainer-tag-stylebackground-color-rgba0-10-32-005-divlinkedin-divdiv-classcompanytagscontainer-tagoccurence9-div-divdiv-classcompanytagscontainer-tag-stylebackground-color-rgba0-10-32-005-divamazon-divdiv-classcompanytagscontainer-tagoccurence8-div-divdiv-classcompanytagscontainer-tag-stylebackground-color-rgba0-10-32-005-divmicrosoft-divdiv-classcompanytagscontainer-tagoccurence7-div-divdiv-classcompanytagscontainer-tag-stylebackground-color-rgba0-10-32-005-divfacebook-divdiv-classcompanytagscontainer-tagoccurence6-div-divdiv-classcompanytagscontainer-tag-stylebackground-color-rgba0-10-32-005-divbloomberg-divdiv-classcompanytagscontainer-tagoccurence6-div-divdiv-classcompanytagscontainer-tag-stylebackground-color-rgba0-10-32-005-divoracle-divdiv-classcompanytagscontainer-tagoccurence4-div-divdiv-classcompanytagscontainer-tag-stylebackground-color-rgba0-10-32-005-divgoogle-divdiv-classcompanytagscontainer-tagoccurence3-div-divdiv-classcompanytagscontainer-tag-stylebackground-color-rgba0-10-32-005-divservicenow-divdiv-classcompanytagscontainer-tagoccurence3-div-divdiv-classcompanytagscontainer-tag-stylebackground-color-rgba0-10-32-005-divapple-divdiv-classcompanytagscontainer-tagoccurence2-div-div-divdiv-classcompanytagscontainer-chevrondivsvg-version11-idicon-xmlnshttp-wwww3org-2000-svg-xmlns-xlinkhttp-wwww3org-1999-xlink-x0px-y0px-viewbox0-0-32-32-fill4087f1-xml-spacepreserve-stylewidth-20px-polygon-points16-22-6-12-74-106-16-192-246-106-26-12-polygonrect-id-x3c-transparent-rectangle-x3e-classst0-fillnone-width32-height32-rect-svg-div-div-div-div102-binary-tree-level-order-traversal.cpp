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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ansVector;
    queue<pair<TreeNode*, int>> helperQueue;
    if (root != nullptr) {
        helperQueue.push({root, 0});
    }

    while (!helperQueue.empty()) {
        pair<TreeNode*, int> currNode = helperQueue.front();
        helperQueue.pop();

        // Ensure there's a vector for the current level
        if (ansVector.size() <= currNode.second) {
            ansVector.push_back({});
        }

        ansVector[currNode.second].push_back(currNode.first->val);

        if (currNode.first->left != nullptr) {
            helperQueue.push({currNode.first->left, currNode.second + 1});
        }
        if (currNode.first->right != nullptr) {
            helperQueue.push({currNode.first->right, currNode.second + 1});
        }
    }

    return ansVector;
}


};