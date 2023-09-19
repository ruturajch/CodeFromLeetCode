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
    pair<int, int> diameter(TreeNode *root)
    {

        if (root == NULL)
            return pair<int, int>(-1, -1);
        pair<int, int> ansLeft = diameter(root->left);
        pair<int, int> ansRight = diameter(root->right);
        ansLeft.first = ansLeft.first == -1 ? 0 : ansLeft.first + 1;
        ansRight.first = ansRight.first == -1 ? 0 : ansRight.first + 1;
        pair<int, int> ans = pair<int, int>(max(ansLeft.first, ansRight.first), max(ansLeft.second, max(ansRight.second, ansLeft.first + ansRight.first)));
        //cout << root->val << " " << ans.first << " " << ans.second << endl;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        pair<int, int> ans = diameter(root);
        return max(ans.first, ans.second);
    }
};