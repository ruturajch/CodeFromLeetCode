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
    void invert(TreeNode* root, TreeNode*& ansNode) {
    if (root == NULL) {
        ansNode = NULL; // Set the ansNode to NULL for leaf nodes.
        return;
    }
    
    ansNode = new TreeNode(root->val);
    invert(root->right, ansNode->left);
    invert(root->left, ansNode->right);
}

TreeNode* invertTree(TreeNode* root) {
    TreeNode* ansNode = nullptr; // Initialize ansNode to nullptr
    invert(root, ansNode);
    return ansNode;
}

};