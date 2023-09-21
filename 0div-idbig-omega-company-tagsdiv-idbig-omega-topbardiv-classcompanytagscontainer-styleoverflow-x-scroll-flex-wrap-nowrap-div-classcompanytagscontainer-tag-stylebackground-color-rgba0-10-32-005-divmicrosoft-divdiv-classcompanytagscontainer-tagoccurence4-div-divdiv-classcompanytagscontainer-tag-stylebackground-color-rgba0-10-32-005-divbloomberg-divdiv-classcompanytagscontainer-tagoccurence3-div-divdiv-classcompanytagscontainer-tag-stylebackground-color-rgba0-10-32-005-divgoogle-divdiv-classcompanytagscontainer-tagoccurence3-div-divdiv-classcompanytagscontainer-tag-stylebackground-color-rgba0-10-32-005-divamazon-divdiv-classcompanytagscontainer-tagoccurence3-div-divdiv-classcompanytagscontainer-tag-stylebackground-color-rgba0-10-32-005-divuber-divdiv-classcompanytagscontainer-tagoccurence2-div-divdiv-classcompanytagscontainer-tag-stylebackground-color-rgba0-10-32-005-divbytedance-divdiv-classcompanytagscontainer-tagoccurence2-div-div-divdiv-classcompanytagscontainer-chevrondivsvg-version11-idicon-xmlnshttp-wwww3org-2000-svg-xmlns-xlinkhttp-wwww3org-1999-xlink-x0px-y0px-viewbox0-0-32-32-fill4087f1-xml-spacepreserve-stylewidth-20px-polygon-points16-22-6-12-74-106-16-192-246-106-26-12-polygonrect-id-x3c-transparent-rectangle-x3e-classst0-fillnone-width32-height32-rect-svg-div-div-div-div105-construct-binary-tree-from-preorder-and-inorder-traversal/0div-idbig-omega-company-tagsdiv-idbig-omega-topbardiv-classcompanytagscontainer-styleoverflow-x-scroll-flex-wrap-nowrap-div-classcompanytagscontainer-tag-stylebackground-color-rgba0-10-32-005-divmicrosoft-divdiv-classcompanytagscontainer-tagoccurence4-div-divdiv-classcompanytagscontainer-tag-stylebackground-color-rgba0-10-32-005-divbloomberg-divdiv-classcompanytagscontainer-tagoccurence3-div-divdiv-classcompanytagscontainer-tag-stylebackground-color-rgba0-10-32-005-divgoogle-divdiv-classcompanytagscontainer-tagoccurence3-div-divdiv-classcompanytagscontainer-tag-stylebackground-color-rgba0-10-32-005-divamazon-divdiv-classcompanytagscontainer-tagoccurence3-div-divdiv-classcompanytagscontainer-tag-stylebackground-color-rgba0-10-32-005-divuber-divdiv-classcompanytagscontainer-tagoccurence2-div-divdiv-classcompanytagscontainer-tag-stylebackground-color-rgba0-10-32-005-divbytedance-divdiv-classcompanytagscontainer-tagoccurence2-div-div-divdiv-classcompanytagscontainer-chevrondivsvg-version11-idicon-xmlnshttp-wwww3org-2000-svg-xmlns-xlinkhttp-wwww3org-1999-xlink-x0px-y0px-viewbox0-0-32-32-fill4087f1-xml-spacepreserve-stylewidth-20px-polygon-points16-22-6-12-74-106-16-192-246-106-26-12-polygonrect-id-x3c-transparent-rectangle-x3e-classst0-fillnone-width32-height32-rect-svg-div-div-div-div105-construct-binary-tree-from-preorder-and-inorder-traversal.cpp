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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};